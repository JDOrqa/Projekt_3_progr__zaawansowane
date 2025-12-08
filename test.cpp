#include "pch.h"
#include "gtest/gtest.h"
#include "../MergeSortProject/MergeSort.h"
#include <vector>

TEST(MergeSortTests, PosortowaneRosnaco)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 1,2,3,4,5 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTests, OdwroconaKolejnosc)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 5,4,3,2,1 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTests, Randomowe)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 10,3,6,1,2 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 6, 10}));
}

TEST(MergeSortTests, TylkoUjemne)
{
    MergeSort<int> sort;
    std::vector<int> arr = { -5,-1,-9,-2,-3 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-9, -5, -3, -2, -1}));
}

TEST(MergeSortTests, UjemneIDodatnie)
{
    MergeSort<int> sort;
    std::vector<int> arr = { -3,10,-1,0,4 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -1, 0, 4, 10}));
}

TEST(MergeSortTests, Pusta)
{
    MergeSort<int> sort;
    std::vector<int> arr;
    EXPECT_NO_THROW(sort.sort(arr)); //bez rzucania wyjatkiem
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTests, JedenElement)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 5 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{5}));
}

TEST(MergeSortTests, Duplikaty)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 3,1,2,1,3 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 1, 2, 3, 3}));
}

TEST(MergeSortTests, UjemneDuplikaty)
{
    MergeSort<int> sort;
    std::vector<int> arr = { -1,-3,-1,-2 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -2, -1, -1}));
}

TEST(MergeSortTests, DodatnieIUjemneZDuplikatami)
{
    MergeSort<int> sort;
    std::vector<int> arr = { -2,3,3,-2,0,5 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-2, -2, 0, 3, 3, 5}));
}

TEST(MergeSortTests, DwaElementy)
{
    MergeSort<int> sort;
    std::vector<int> arr = { 1,2 };
    sort.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2}));
}

TEST(MergeSortTests, WieleElementow)
{
    MergeSort<int> sort;
    std::vector<int> arr(200);
    for (int i = 0; i < 200; ++i)
        arr[i] = 200 - i;

    sort.sort(arr);

    for (int i = 0; i < 200; ++i)
        EXPECT_EQ(arr[i], i + 1);
}

TEST(MergeSortTests, WieleElementowzDuplikatamiUjemneDodatnie) {
    MergeSort<int> sorter;
    std::vector<int> arr;

    
    // Liczby ujemne
    for (int i = -50; i < 0; i++) {
        arr.push_back(i);
    }

    // Liczby dodatnie
    for (int i = 0; i < 50; i++) {
        arr.push_back(i);
    }

    // Duplikaty 
    arr.push_back(-25);  
    arr.push_back(-25);  
    arr.push_back(10);   
    arr.push_back(10);   
    arr.push_back(10);   
    arr.push_back(0);    
    arr.push_back(0);    
    arr.push_back(-100);
    arr.push_back(100);
    arr.push_back(-1);
    arr.push_back(1);

    
    EXPECT_GT(arr.size(), 100);

   
    sorter.sort(arr);

    // Czy posortowana rosnaco
    for (size_t i = 0; i < arr.size() - 1; i++) {
        EXPECT_LE(arr[i], arr[i + 1])
            << "Element na pozycji " << i << " (" << arr[i]
            << ") jest większy od elementu na pozycji " << i + 1
            << " (" << arr[i + 1] << ")";
    }


    // czy duplikaty są zachowane
    
    int count_10 = 0;
    int count_minus_25 = 0;
    int count_0 = 0;

    for (int num : arr) {
        if (num == 10) count_10++;
        if (num == -25) count_minus_25++;
        if (num == 0) count_0++;
    }

    EXPECT_GE(count_10, 4);
    EXPECT_GE(count_minus_25, 3);
    EXPECT_GE(count_0, 3) ;

    //  czy pierwszy element to najmniejszy
    EXPECT_EQ(arr[0], -100) ;

    //  czy ostatni element to największy
    EXPECT_EQ(arr[arr.size() - 1], 100) ;
}
//  TESTY DOUBLE 

TEST(MergeSortTests, PosortowaneRosnaco_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    sort.sort(arr);

    std::vector<double> expected = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, OdwroconaKolejnosc_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    sort.sort(arr);

    std::vector<double> expected = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, Randomowe_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 10.5, 3.3, 6.6, 1.1, 2.2 };
    sort.sort(arr);

    std::vector<double> expected = { 1.1, 2.2, 3.3, 6.6, 10.5 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, TylkoUjemne_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { -5.5, -1.1, -9.9, -2.2, -3.3 };
    sort.sort(arr);

    std::vector<double> expected = { -9.9, -5.5, -3.3, -2.2, -1.1 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, UjemneIDodatnie_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { -3.3, 10.5, -1.1, 0.0, 4.4 };
    sort.sort(arr);

    std::vector<double> expected = { -3.3, -1.1, 0.0, 4.4, 10.5 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, Pusta_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr;
    EXPECT_NO_THROW(sort.sort(arr));
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTests, JedenElement_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 5.5 };
    sort.sort(arr);

    std::vector<double> expected = { 5.5 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, Duplikaty_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 3.3, 1.1, 2.2, 1.1, 3.3 };
    sort.sort(arr);

    std::vector<double> expected = { 1.1, 1.1, 2.2, 3.3, 3.3 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, UjemneDuplikaty_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { -1.1, -3.3, -1.1, -2.2 };
    sort.sort(arr);

    std::vector<double> expected = { -3.3, -2.2, -1.1, -1.1 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, DwaElementy_Double)
{
    MergeSort<double> sort;
    std::vector<double> arr = { 1.1, 2.2 };
    sort.sort(arr);

    std::vector<double> expected = { 1.1, 2.2 };
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTests, WieleElementowzDuplikatamiUjemneDodatnie_Double)
{
    MergeSort<double> sorter;
    std::vector<double> arr;

    
    arr.push_back(-25.0); arr.push_back(-25.0);
    arr.push_back(10.0); arr.push_back(10.0); arr.push_back(10.0);
    arr.push_back(0.0); arr.push_back(0.0);
    arr.push_back(-100.0);
    arr.push_back(100.0);
    arr.push_back(-1.0);
    arr.push_back(1.0);

   
    for (int i = 0; i < 95; i++) {
        arr.push_back(static_cast<double>(i) - 47.5); // sekwencja liczb double od -47.5 do 46.5
    }

    EXPECT_GT(arr.size(), 100) << "Rozmiar tablicy: " << arr.size();

    sorter.sort(arr);

    
    for (size_t i = 0; i < arr.size() - 1; i++) {
        EXPECT_LE(arr[i], arr[i + 1])
            << "Tablica nieposortowana na pozycjach " << i << " i " << i + 1;
    }

    // Prostsze sprawdzenie granic
    EXPECT_LE(arr[0], -99.9) << "Pierwszy element powinien być <= -99.9, jest: " << arr[0];
    EXPECT_GE(arr[arr.size() - 1], 99.9) << "Ostatni element powinien być >= 99.9, jest: " << arr[arr.size() - 1];
}
