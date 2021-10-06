#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

class Node
{
    friend class List;
    string val;
    int flag;
    Node *link;
    Node *down;

    public:
        Node() {
            val = "NULL";
            link = NULL;
            flag=0;
            down=NULL;
        }
        Node(string v) {
            val = v;
            link = NULL;
            down=NULL;
            flag=0;

        }
};

class List
{

    Node *head;
    public:
        List() {
            head = new Node();


        }
        void append(string,string);
        void append(string,string,string);
        void append(string);
        void show_cat();
        void show();
        void show(Node*);
        void display(Node*);
        Node* search_child(string,string);
        Node* search_element(string);
        Node* search_child_child(Node*,string);
};
Node* List::search_element(string v){
Node * temp=head;
while(temp!=NULL){
    if(temp->val==v)
        return temp;
    temp=temp->link;
}

}


Node* List::search_child(string a,string b){
Node* temp= head;
while(temp!=NULL){
    if(temp->val==a){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}


Node* List::search_child_child(Node* a,string b){
Node* temp= a->down;
while(temp!=NULL){
    if(temp->flag==1){
        Node* temp2= temp->down;
        while(temp2!=NULL){
                if(temp2->val==b)
                    return temp2;
            temp2=temp2->link;
        }

    }
     temp=temp->link;
}


}
void List::append(string item)
{
    Node *pivot = new Node(item);
    if (head==NULL) {
        head= pivot;
    }
    else {
        Node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = pivot;
    }

}


void List::append(string v,string item)
{
    Node* newnode= new Node(item);

    Node *found= search_element(v);
    if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node*temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }

}
void List::append(string a,string b, string c){
Node* newnode=new Node(c);
Node* found= search_child(a,b);
if(found->down==NULL){
            found->flag=1;
        found->down=newnode;
    }
    else{

        Node* temp= found->down;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }




}


void List::show()
{
   Node* temp= head;
    temp=temp->link;
   while(temp!=NULL){
    cout<<"\t"<<temp->val<<endl;
    if(temp->flag==1){
        display(temp);
    }
    temp=temp->link;
   }
}

void List::show_cat(){
Node* temp= head;
temp=temp->link;
int i=1;
while(temp->link!=NULL){
    cout<<"\t\t\t\t"<<i<<" ) "<<temp->val<<endl;
    temp=temp->link;
    i++;
}


}
void List::display(Node* h){
    Node* temp=h->down;
    while(temp!=NULL){
            cout<<"\t\t#  "<<temp->val<<endl;
            if(temp->flag==1){
                show(temp);
            }
        temp=temp->link;
    }

}

void List::show(Node* h){
 Node* temp=h->down;
    while(temp!=NULL){
            cout<<"\t\t\t-->  "<<temp->val<<endl;
        temp=temp->link;
    }
}


class printshoplist{
List l;
public:
    printshoplist(){
        l.append("HYPERMARKET");
        l.append("ELECTRONICS");
        l.append("SPORTS");
        l.append("FOOTWEAR");
        l.append("APPARELS");
        l.append("JEWELLERY & WATCHES");
        l.append("BEAUTY & PERSONAL CARE");
        l.append("HOME DECOR");
        l.append("MULTI BRAND");
        l.append("BAGS & ACCESSORIES");
        l.append("ENTERTAINMENT");
        l.append("RESTAURANT");
        l.append("FOOD COURT");
        l.append("CAFE & QUICK BITES");
        l.append("HYPERMARKET","MARKET 99");
        l.append("HYPERMARKET","SPAR");
        l.append("ELECTRONICS","SAMSUNG");
        l.append("ELECTRONICS","OPPO");
        l.append("ELECTRONICS","ONE PLUS");
        l.append("ELECTRONICS","APPLE");
        l.append("ELECTRONICS","CROMA");
        l.append("SPORTS","ADIDAS");
        l.append("SPORTS","NIKE");
        l.append("SPORTS","PUMA");
        l.append("SPORTS","DECATHLON");
        l.append("FOOTWEAR","BATA");
        l.append("FOOTWEAR","METRO");
        l.append("FOOTWEAR","NEEDLE DUST");
        l.append("APPARELS","MEN");
        l.append("APPARELS","WOMEN");
        l.append("APPARELS","UNISEX");
        l.append("APPARELS","KIDS");
        l.append("JEWELLERY & WATCHES","MIA");
        l.append("JEWELLERY & WATCHES","HELIAS");
        l.append("JEWELLERY & WATCHES","BLUESTONE");
        l.append("JEWELLERY & WATCHES","CARAT LANE");
        l.append("JEWELLERY & WATCHES","DANIEL WELLINGTON");
        l.append("BEAUTY & PERSONAL CARE","KAMA");
        l.append("BEAUTY & PERSONAL CARE","KAYA");
        l.append("BEAUTY & PERSONAL CARE","MAC");
        l.append("BEAUTY & PERSONAL CARE","OZONE");
        l.append("BEAUTY & PERSONAL CARE","KIKO");
        l.append("BEAUTY & PERSONAL CARE","NYKAA");
        l.append("BEAUTY & PERSONAL CARE","INNISFREE");
        l.append("HOME DECOR","HOME CENTRE");
        l.append("HOME DECOR","PURE");
        l.append("HOME DECOR","CHUMBAK");
        l.append("HOME DECOR","CRAFT STUDIO INDIA");
        l.append("MULTI BRAND","LIFESTYLE");
        l.append("MULTI BRAND","MAX");
        l.append("BAGS & ACCESSORIES","VIP");
        l.append("BAGS & ACCESSORIES","LENSKART.COM");
        l.append("BAGS & ACCESSORIES","FOSSIL");
        l.append("BAGS & ACCESSORIES","BEAU MONDE");
        l.append("ENTERTAINMENT","PVR");
        l.append("ENTERTAINMENT","LOCK AND LOAD");
        l.append("RESTAURANT","BIRYANI BLUES");
        l.append("RESTAURANT","CHILI'S");
        l.append("RESTAURANT","THE BEER CAFE");
        l.append("RESTAURANT","DELHI HEIGHTS");
        l.append("RESTAURANT","CASTLE'S BARBEQUE");
        l.append("FOOD COURT","BURGER KING");
        l.append("FOOD COURT","DOMINOES");
        l.append("FOOD COURT","HALDIRAM");
        l.append("FOOD COURT","KFC");
        l.append("FOOD COURT","PIZZA HUT");
        l.append("FOOD COURT","WOW MOMO");
        l.append("FOOD COURT","SUBWAY");
        l.append("FOOD COURT","SAMIYOSA");
        l.append("FOOD COURT","BERCO'S");
        l.append("FOOD COURT","DOSA VILLAGE");
        l.append("CAFE & QUICK BITES","STARBUCKS");
        l.append("CAFE & QUICK BITES","IHOP");
        l.append("CAFE & QUICK BITES","CHAAYOS");
        l.append("CAFE & QUICK BITES","HONEY & DOUGH");
        l.append("APPARELS","MEN","ARROW");
        l.append("APPARELS","MEN","JACK & JONES");
        l.append("APPARELS","MEN","OCTAVE");
        l.append("APPARELS","MEN","LOUIS PHILIPPE");
       l.append("APPARELS","WOMEN","BIBA");
        l.append("APPARELS","WOMEN","MADAME");
        l.append("APPARELS","WOMEN","AURELIA");
        l.append("APPARELS","UNISEX","ZARA");
        l.append("APPARELS","UNISEX","CALVIN KLEIN");
        l.append("APPARELS","UNISEX","JOCKEY");
        l.append("APPARELS","KIDS","ICONIC KIDS");
        l.append("APPARELS","KIDS","MOTHER CARE");


    }

    void showcat(){
    l.show_cat();
    }
    void showshops(){
    l.show();
    }
    void show_shop_per_cat(string s){
    Node* h=l.search_element(s);
    l.display(h);
    }
};
