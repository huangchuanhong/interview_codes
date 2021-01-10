#include <iostream>
#include <set>
using namespace std;

struct Node
{
  Node(int v):val(v),next(nullptr){}
  int val;
  Node *next;
};

Node *create_list()
{
  Node *head = new Node(1);
  Node *p = head;
  p->next = new Node(2);
  p = p->next;
  p->next = new Node(3);
  p = p->next;
  p->next = new Node(4);
  p = p->next;
  p->next = head;
  return head;
}

bool has_loop(Node *head)
{
  set<Node *> ps;
  Node *p = head; 
  while (p != nullptr)
  {
    if (ps.find(p) == ps.end())
      ps.insert(p);
    else
      return true;
    p = p->next;
  }
  return false;
}

bool has_loop2(Node *head)
{
  if (head == nullptr) return false;
  Node *p1 = head->next;
  if (p1 == nullptr) return false;
  Node *p2 = p1->next;
  while (p1!=p2)
  {
    if (p2 == nullptr) return false;
    p1 = p1->next;
    p2 = p2->next;
    if (p2 == nullptr) return false;
    if (p2 == p1) return true;
    p2 = p2->next;
    if (p2 == nullptr) return false;
    if (p1 == p2) return true;
  }  
  return true;
}

int main()
{
  Node *head = create_list();
  bool b = has_loop2(head);
  cout << b<<endl;   
}
