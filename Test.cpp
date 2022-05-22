#include <iostream>
#include <string>
#include <vector>
#include "OrgChart.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE("School"){
    OrgChart School;
    School.add_root("Teacher")
      .add_sub("Teacher", "TA1")      
      .add_sub("Teacher", "TA2")    
      .add_sub("TA1", "cooper")  
      .add_sub("TA1", "sami")
      .add_sub("TA2", "Tommy");
    
    std::string s = "";
    for (auto it = School.begin_level_order(); it != School.end_level_order(); ++it){
        s+=(*it) + " ";
    } // prints: Teacher TA1 TA2 cooper sami Tommy
    CHECK(s=="Teacher TA1 TA2 cooper sami Tommy ");

    s="";
    for (auto it = School.begin_reverse_order(); it != School.reverse_order(); ++it){
        s+=(*it) + " ";
    } // prints: cooper sami Tommy TA1 TA2 Teacher
    CHECK(s=="cooper sami Tommy TA1 TA2 Teacher ");

    s="";
    for (auto it=School.begin_preorder(); it!=School.end_preorder(); ++it) {
        s+=(*it) + " ";
    }  // prints: Teacher TA1 cooper sami TA2 Tommy
    CHECK(s=="Teacher TA1 cooper sami TA2 Tommy ");

    s="";
    for (auto element : School){ // this should work like level order
        s+=element + " ";
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    CHECK(s=="Teacher TA1 TA2 cooper sami Tommy");

    s="";
    for (auto it = School.begin_level_order(); it != School.end_level_order(); ++it)
    {
        s+=(*it) + " ";
    } // prints: 7 3 3 6 4 5
    CHECK(s=="7 3 3 6 4 5 ");

    CHECK_NOTHROW(School.add_sub("Teacher", "TA3"));

}

TEST_CASE("Factory"){
    OrgChart Factory;
    Factory.add_root("Manager")
      .add_sub("Manager", "AM1")      
      .add_sub("Manager", "AM2")    
      .add_sub("AM1", "cooper")  
      .add_sub("AM1", "sami")
      .add_sub("AM2", "Tommy");
    
    std::string s = "";
    for (auto it = Factory.begin_level_order(); it != Factory.end_level_order(); ++it){
        s+=(*it) + " ";
    } // prints: Manager AM1 AM2 cooper sami Tommy
    CHECK(s=="Manager AM1 AM2 cooper sami Tommy ");

    s="";
    for (auto it = Factory.begin_reverse_order(); it != Factory.reverse_order(); ++it){
        s+=(*it) + " ";
    } // prints: cooper sami Tommy AM1 AM2 Manager
    CHECK(s=="cooper sami Tommy AM1 AM2 Manager ");

    s="";
    for (auto it=Factory.begin_preorder(); it!=Factory.end_preorder(); ++it) {
        s+=(*it) + " ";
    }  // prints: Manager AM1 cooper sami AM2 Tommy
    CHECK(s=="Manager AM1 cooper sami AM2 Tommy ");

    s="";
    for (auto element : Factory){ // this should work like level order
        s+=element + " ";
    } 
    CHECK(s=="Manager AM1 AM2 cooper sami Tommy");

    s="";
    for (auto it = Factory.begin_level_order(); it != Factory.end_level_order(); ++it)
    {
        s+=(*it) + " ";
    } // prints: 7 3 3 6 4 5
    CHECK(s=="7 3 3 6 4 5 ");
    CHECK_NOTHROW(Factory.add_sub("Manager", "TA3"));
    CHECK_THROWS(Factory.add_sub("Teacher", "TA3"));
}

TEST_CASE("Court"){
    OrgChart Court;
    Court.add_root("Judge")
      .add_sub("Judge", "defendant")       
      .add_sub("Judge", "prosecuter")    
      .add_sub("defendant", "cooper")  
      .add_sub("prosecuter", "sami");
    
    std::string s = "";
    for (auto it = Court.begin_level_order(); it != Court.end_level_order(); ++it){
        s+=(*it) + " ";
    } // prints: Teacher defendant prosecuter cooper sami 
    CHECK(s=="Judge defendant prosecuter cooper sami ");

    s="";
    for (auto it = Court.begin_reverse_order(); it != Court.reverse_order(); ++it){
        s+=(*it) + " ";
    } // prints: cooper sami Tommy defendant prosecuter Judge
    CHECK(s=="cooper sami defendant prosecuter Judge ");

    s="";
    for (auto it=Court.begin_preorder(); it!=Court.end_preorder(); ++it) {
        s+=(*it) + " ";
    }  // prints: Judge TA1 cooper prosecuter sami 
    CHECK(s=="Judge defendant cooper prosecuter sami  ");

    s="";
    for (auto element : Court){ // this should work like level order
        s+=element + " ";
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    CHECK(s=="Judge defendant prosecuter cooper sami ");

    s="";
    for (auto it = Court.begin_level_order(); it != Court.end_level_order(); ++it)
    {
        s+=(*it) + " ";
    } // prints: 5 9 10 6 4 
    CHECK(s=="5 9 10 6 4 ");

    CHECK_NOTHROW(Court.add_sub("Judge", "TA3"));
    CHECK_NOTHROW(Court.add_sub("sami", "private investigator"));

}

