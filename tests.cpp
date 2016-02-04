//*****************************************************************
//  tests.cpp
//
//  Written by George Liao on Jan 25, 2016.
//
//*****************************************************************

#include "Linked_list.cpp"
#include <gtest/gtest.h>
//#include <gmock/gmock.h>

//using ::testing::Return;

TEST(Get_mid_r3rd_node_test, normal_cases_odd_number_elementes){

    int a[5] = {1,2,3,4,5};
    LinkedList LL(a, 5);
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(3, p_mid->m_key);
    ASSERT_EQ(3, p_r3rd->m_key);
}

TEST(Get_mid_r3rd_node_test, normal_cases_even_number_elementes){

    int a[6] = {1,2,3,4,5,6};
    LinkedList LL(a, 6);
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(4, p_mid->m_key);
    ASSERT_EQ(4, p_r3rd->m_key);
}


TEST(Get_mid_r3rd_node_test, corner_cases_zero_element){

    LinkedList LL;
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(NULL, p_mid);
    ASSERT_EQ(NULL, p_r3rd);
}

TEST(Get_mid_r3rd_node_test, corner_cases_one_element){

    int a[1] = {1};
    LinkedList LL(a, 1);
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(1, p_mid->m_key);
    ASSERT_EQ(NULL, p_r3rd);
}

TEST(Get_mid_r3rd_node_test, corner_cases_two_element){

    int a[2] = {1,2};
    LinkedList LL(a, 2);
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(2, p_mid->m_key);
    ASSERT_EQ(NULL, p_r3rd);
}

TEST(Get_mid_r3rd_node_test, corner_cases_three_element){

    int a[3] = {1,2,3};
    LinkedList LL(a, 3);
    List_node *p_mid, *p_r3rd;
    LL.Get_mid_r3rd_node(&p_mid, &p_r3rd);
    ASSERT_EQ(2, p_mid->m_key);
    ASSERT_EQ(1, p_r3rd->m_key);
}



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    //::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
