#include "OrgChart.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
namespace ariel
{
    OrgChart::OrgChart(){
        this->head = nullptr;
    }
    OrgChart &OrgChart::add_root(const std::string &value)
    {
        if (value.empty()){
            throw std::runtime_error("empty name");
        }
        if (head == nullptr){
            Node* n =new Node(value);
            this->head = n;
            sNodes.push_back(n->val);
            allNodes.push_back(n);
            return *this;
        }

        // this->allNodes.push_back(n);
        std::vector<std::string>::iterator it;
        it = sNodes.begin();
        for (unsigned long i = 0; i < sNodes.size(); i++)
        {
            if (sNodes[i] == head->val)
            {   
                sNodes.erase(it);
                break;
            }
            it++;
        }

        sNodes.push_back(value);
        this->head->val = value;
        return *this;
    }
    OrgChart &OrgChart::add_sub(const std::string &above, const std::string &value){
        if (head == nullptr){
            throw std::runtime_error("never initialize tree");
        }

        for(unsigned long i = 0; i< allNodes.size(); i++){

            if(sNodes[i] == above){

                Node* n = new Node(value);
                
                allNodes[i]->subs.push_back(n);
                allNodes.push_back(n);
                sNodes.push_back(n->val);
                return *this;
            }
        }
        throw std::runtime_error("Can't find the father");
    }
    
    //we put all boys in the same level and add the below level after (fifo)
    OrgChart::iterator OrgChart::begin_level_order(){
        if (head == nullptr){
            throw std::runtime_error("never initialize tree");
        }
        std::queue<Node*> q;
        q.push(head);
        std::vector<Node*> returnVec;
        while (!q.empty()){
            Node* n = q.front();
            q.pop();
            returnVec.push_back(n);
            if(n->subs.empty()){continue;}
            std::vector<Node*> TempVec(n->subs);
            for (unsigned long i = 0; i < TempVec.size(); i++){
                q.push(TempVec[i]);
            }
            TempVec.clear();
        }
        allNodes.clear();
        allNodes = returnVec;
        sNodes.clear();
        for (Node* n : allNodes){sNodes.push_back(n->val);}
        for (unsigned long i = 0; i < allNodes.size(); i++){
            allNodes[i]->next = allNodes[i+1];
        }
        // iterator it = iterator{allNodes[0]};
        return iterator{allNodes[0]};
    }


    OrgChart::iterator OrgChart::begin_reverse_order() {
        if (head == nullptr){
            throw std::runtime_error("never initialize tree");
        }

        std::queue<Node*> q;
        q.push(head);
        std::vector<Node*> returnVec;
        std::stack<std::vector<Node*>> st;
        while(!q.empty()){
            std::queue<Node*> qTemp;
            std::vector<Node*> TVec;
            //all node childs
            while(!q.empty()){
                Node* n = q.front();
                q.pop();
                if(n->subs.empty()){continue;}
                std::vector<Node*> TempVec(n->subs);
                for (unsigned long i = 0; i < TempVec.size() ; i++){
                    qTemp.push(TempVec[i]);
                }
                TVec.insert(TVec.end(), TempVec.begin(), TempVec.end());
                TempVec.clear();
            }
            while(!qTemp.empty()){
                Node* na = qTemp.front();
                q.push(na);
                qTemp.pop();
            }
            st.push(TVec);
            TVec.clear();
        }
        //lifo
        while(!st.empty()){
            std::vector<Node*>tempVec(st.top());
            st.pop();
            for (unsigned long i = 0; i < tempVec.size(); i++)
            {
                returnVec.push_back(tempVec[i]);
            }            
        }
        returnVec.push_back(head);
        allNodes.clear();
        allNodes = returnVec;
        sNodes.clear();
        for (Node* n : allNodes){sNodes.push_back(n->val);}
        for (unsigned long i = 0; i < allNodes.size(); i++){
            allNodes[i]->next = allNodes[i+1];
        }
        std::cout<< allNodes.size() << std::endl;

        return iterator{allNodes[0]};
    }
    OrgChart::iterator OrgChart::begin_preorder() {
        if (head == nullptr){
            throw std::runtime_error("never initialize tree");
        }
        std::stack<Node*> st;
        st.push(head);
        std::vector<Node*> returnVec;
        while (!st.empty()){
            Node* n = st.top();
            st.pop();
            returnVec.push_back(n);
            if(n->subs.empty()){continue;}
            std::vector<Node*> TempVec(n->subs);
            std::reverse(TempVec.begin(), TempVec.end());
            for (unsigned long i = 0; i < TempVec.size(); i++){
                st.push(TempVec[i]);
            }
            TempVec.clear();
        }
        allNodes.clear();
        allNodes = returnVec;
        sNodes.clear();
        for (Node* n : allNodes){sNodes.push_back(n->val);}
        for (unsigned long i = 0; i < allNodes.size(); i++){
            allNodes[i]->next = allNodes[i+1];
        }
        
        return iterator{allNodes[0]};
    }    
}
// namespace ariel
