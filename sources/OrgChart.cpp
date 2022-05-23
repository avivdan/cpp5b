#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <stack>
#include <queue>

#include "OrgChart.hpp"

namespace ariel
{

    OrgChart::OrgChart(){
        level_order = std::vector<std::string>();
        pre_order = std::vector<std::string>();
    }
    OrgChart::~OrgChart(){}
   //also runs over the existing root
    OrgChart &OrgChart::add_root(std::string value){
        this->head->val = value;
        return *this;
    }

    OrgChart &OrgChart::add_sub(std::string above, std::string value){
        Node *subs = this->head;
        if (this->head->val.compare(above) == 0){
            if(this->head->sub == NULL){
                subs->sub = new Node(value, 1);
                return *this;
            }
            subs = subs->sub;
            while (subs->next != NULL){               
                subs = subs->next;
            }
            subs->next = new Node(value, subs->depth + 1);
            return *this;
        }
        //checked for root and now for sons
        //first we go on horizontal list to check if there is the above value
        //after that we continue to next horizontal level and so on
        Node* inlin = inLine(subs, above);
        // inlin = findIt(subs, above);
        if( inlin != NULL ){
            inlin->sub = new Node(value, inlin->depth + 1);
            // std::cout<<inlin->val<<std::endl;
            return *this;
        }
        return *this;
    }

    Node *OrgChart::inLine(Node* src, std::string& above){
        if(src->val.compare(above) == 0){
            return src;
        }
        if(src->sub != NULL){
            Node* n = inLine(src->sub, above);
            if(n != NULL){return n;}
        }
        while (src->next != NULL){
            src = src->next;
            if(src->val.compare(above) == 0){
                return src;
            }
            if(src->sub != NULL){
                Node* n = inLine(src->sub, above);
                if (n != NULL){return n;}
            }
        }
        return NULL;
    }

    void OrgChart::println_src(){
        std::cout<< this->head->val <<std::endl;
        if(this->head->sub != NULL){
            println(this->head->sub);
        }
            
    } 

    void OrgChart::println(Node *src){
        std::cout<< src->val <<std::endl;
        if (src->sub != NULL){
            println(src->sub);
        }
        while(src->next != NULL){
            src = src->next;
            std::cout<< src->val <<std::endl;
            if (src->sub != NULL){
                println(src->sub);
            }
        }
    }

    void OrgChart::set_all_my_kids(){
        level_order.push_back(this->head->val);
        std::vector<std::string> TempVec(all_my_kids(this->head));
        level_order.insert(std::end(level_order), std::begin(TempVec), std::end(TempVec));        
    }
    std::vector<std::string> OrgChart::all_my_kids(Node* src){
        std::vector<std::string> vec;
        if(src->sub != NULL){
            Node* subs = src->sub;
            vec.push_back(subs->val);
            while(subs->next != NULL){
                subs = subs->next;
                vec.push_back(subs->val);

            }
            src = src->sub;
            std::vector<std::string> TempVec(all_my_kids(src));
            vec.insert(std::end(vec), std::begin(TempVec), std::end(TempVec));

            while(src->next != NULL){
                TempVec = all_my_kids(src->next);
                vec.insert(std::end(vec), std::begin(TempVec), std::end(TempVec));
                src = src->next;
            }
        }
        return vec;
    }

    void OrgChart::set_all_my_kids_pre(){
        this->pre_order = all_my_kids_pre(this->head);
    }


    std::vector<std::string> OrgChart::all_my_kids_pre(Node* src){
        std::vector<std::string> vec;
        vec.push_back(src->val); 
        if(src->sub != NULL){
            src = src->sub;
            std::vector<std::string> TempVec(all_my_kids_pre(src));
            vec.insert(std::end(vec), std::begin(TempVec), std::end(TempVec));

            while(src->next != NULL){
                TempVec = all_my_kids_pre(src->next);
                vec.insert(std::end(vec), std::begin(TempVec), std::end(TempVec));
                src = src->next;
            }
        }
        return vec;
    }
    
    std::string* OrgChart::begin_preorder(){
        pre_order.clear();
        set_all_my_kids_pre();
        if (!pre_order.empty())
        {
            return &pre_order[0];
        }
        return nullptr;
    }
    std::string* OrgChart::end_preorder(){
        if (!pre_order.empty())
        {
            return &pre_order[pre_order.size()];
        }
        set_all_my_kids_pre();
        if (!pre_order.empty())
        {
            return &pre_order[pre_order.size()];
        }
        return nullptr;
    }

    void OrgChart::set_all_my_kids_reversed(){
        reversed_level_order.clear();
        reversed_level_order.push_back(this->head->val);
        std::vector<std::string> TempVec(all_my_kids(this->head));
        reversed_level_order.insert(std::end(reversed_level_order), std::begin(TempVec), std::end(TempVec));  
        std::reverse(reversed_level_order.begin(), reversed_level_order.end());
    }
    
    std::string* OrgChart::begin_level_order(){
        level_order.clear();
        set_all_my_kids();
        if (!level_order.empty())
        {
            return &level_order[0];
        }
        return nullptr;
    }
    std::string* OrgChart::end_level_order(){
        if (!level_order.empty())
        {
            return &level_order[level_order.size()];
        }
        set_all_my_kids();
        if (!level_order.empty())
        {
            return &level_order[level_order.size()];
        }
        return nullptr;
    }

    std::string* OrgChart::begin_reverse_order(){
        reversed_level_order.clear();
        set_all_my_kids_reversed();
        if (!reversed_level_order.empty())
        {
            return &reversed_level_order[0];
        }
        return nullptr;
    }
    std::string* OrgChart::reverse_order(){
        if (!reversed_level_order.empty())
        {
            return &reversed_level_order[reversed_level_order.size()];
        }
        set_all_my_kids_reversed();
        if (!reversed_level_order.empty())
        {
            return &reversed_level_order[reversed_level_order.size()];
        }
        return nullptr;
    }
}