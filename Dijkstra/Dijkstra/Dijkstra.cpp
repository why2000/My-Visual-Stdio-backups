#include<iostream>
#include<string>
#define INFTY 0x3f3f3f3;
using namespace std;

int A,B,d;

struct Node
{
    long long distance;
    string color;
    Node*next;
    Node*key;
    Node(){distance=INFTY;color="white";next=NULL;key=NULL;};
};

void AddNode(Node*head,Node*node_a,Node*node_b)
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node_a;
    temp->key=node_b;
}

void TravelList(Node*head)
{
    Node*temp = head;
    temp=temp->next;
    do
    {
         if(temp->color=="white")
         {
              temp->color="black";
              temp->key->distance=temp->distance+head->distance;
         }
         else
         {
              if(temp->distance+head->distance<temp->key->distance)
              {
                   temp->key->distance=temp->distance+head->distance;
              }
         }
    }while(temp->next!=NULL);

}

int main()
{
    int n,lines;
    while(cin>>n>>lines)
    {
        Node* *p = new Node*[n+1];
        p[1]->distance=0;
        for(int i=0;i<lines;i++)
        {
            cin>>A>>B>>d;
            Node *ps = new Node;
            Node *pp = new Node;
            ps->distance=d;
            AddNode(p[A],ps,p[B]);
            AddNode(p[B],ps,p[A]);
        }

        for(int i=1;i<=n;i++)
        {
            TravelList(p[i]);
        }
        cout<<p[n]->distance<<endl;
    }
}
