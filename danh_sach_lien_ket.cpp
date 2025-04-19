
#include <bits/stdc++.h>
using namespace std;
struct node{
   int data;
   struct node *next;//chỉ là 1 con trỏ chỉ đến địa chỉ
};

node* makeNode(int x){ // trả về địa chỉ của node mới tạo
   node *newNode = new node(); //con trỏ tới nút vừa tạo và new node là cấp phát bộ nhớ
   newNode->data = x;
   newNode->next = NULL;
   return newNode;
}
void duyet(node *head){
   while(head!=NULL){
      cout << head->data<<" ";
      head=head->next;
   }
}//do bản thân node head là 1 con trỏ nên khi con trỏ head trong hàm di chuyển không ảnh hưởng đến dslk
void pushfront(node **head,int x){ //do con trỏ trỏ đến con trỏ kiểu node nên cần dùng 2 dấu sao
   node *newNode = makeNode(x);
   newNode->next = *head;//trỏ next của node vừa tạo tới nút đầu tiên //địa chỉ node head trong dslk(toán tử dải tham chiếu)
   *head = newNode; //cập nhật con trỏ head trỏ đến newNode biến nó thành node đầu tiên
}
void pushfront2(node *&head,int x){ //sử dụng truyền tham chiếu cho con trỏ head chỉ có c++
   node *newNode = makeNode(x);
   newNode->next= head;
   head = newNode;
}
void pushback2(node *&head,int x){
   node *temp = head;
   node *newNode = makeNode(x);
   if(head==NULL){
      head=newNode;
      return;
   }
   while (temp->next!=NULL){ //temp là con trỏ chỉ địa vị trí hiện tại
      temp=temp->next;//team->nẽt là con trỏ chỉ đến địa chỉ của nút tiếp theo
   }
   temp->next = newNode;
}
void insert(node *&head,int x,int n){
      node *temp=head;
      if (n==1) {pushfront2(head,x);return;}
      node *newNode= makeNode(x);
      for (int i=1;i<n-1;i++){
         temp=temp->next;
      }
      newNode->next=temp->next;//chèn vào giữa newNode->next sẽ trỏ đến nút tiếp theo thay vì temp->next;
      temp->next=newNode;
}
void popfront(node *&head){
      if (head==NULL) return;
      node *temp=head;
      head=head->next;
      delete temp;
}
void popback(node *&head){
   node *temp=head;
   while (temp->next->next!=NULL){
      temp=temp->next;
   }
   node *last=temp->next;
   temp->next=NULL;
   delete last;
}
void pop(node *&head,int n){
   if (n<1 || head==NULL) return;
   if (n==1) {
      popfront(head);
      return;
   }
   node *temp=head;
   for (int i=1;i<n-1;i++){
      temp=temp->next;
   }
   if (temp->next == NULL) return; // Nếu n vượt quá số phần tử, thoát
   if (temp->next->next==NULL){
      popback(head);
   }
   else{
      node *pop1=temp->next;
      temp->next=temp->next->next;
      delete pop1;
   }
}
int main(){
   node *head = NULL;
   // for (int i=1;i<=5;i++){
   //    pushfront(&head,i); // do con trỏ chỉ đến con trỏ nên gọi hàm cần địa chỉ
   // }
   // for (int i=1;i<=10;i++){
   //    pushback2(head,i);
   // }
   // insert(head,5,3);
   // popfront(head);
   // popback(head);
   // pop(head,3);
   map<int,int> mp;
   int n,x; cin >> n;
   for (int i=1;i<=n;i++){
      cin >> x;
      if (mp[x]==0){
         pushback2(head,x);
         mp[x]++;
      }
   }
   popfront(head);
   duyet(head); //bản thân head là con trỏ nên không cần địa chỉ
}

// NULL con tro;
// null gia tri mot xau ky tu;