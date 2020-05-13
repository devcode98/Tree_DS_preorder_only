#include<iostream>
using namespace std;

class node
  {
  private:
    int data;
    node *left;
    node *right;
  public:
    node *right_node();
    node *pre_order();
    node *left_node();
    node *display_values();
    node *create_node(int data1)
       {
         data=data1;
         left=NULL;
         right=NULL;
       }

   node *pre_order(node *ptr)
        {
          // this functon is for getting the pre order traversal of the tree //
          // we will be printing the node no matter what is the outcome //
          cout<<"The val is :"<<ptr->data;
          // now this will be acting like a root //
          // now we will be moving towards the node on the left//
          if (ptr->left!=NULL)
             {
               ptr->left=pre_order(ptr->left);
             }
          if (ptr->left==NULL && ptr->right==NULL)
             {
               // we have reached the end of the list//
               return ptr;
             }
          if (ptr->right!=NULL)
             {
               ptr->right=pre_order(ptr->right);
             }
          if (ptr->right==NULL && ptr->left==NULL)
             {
               return ptr;
             }


        }
    node *display_values(node *ptr)
        {
          cout<<ptr->data<<endl;
          ptr=ptr->left;
          cout<<ptr->data<<endl;
          ptr=ptr->right;
          cout<<ptr->data<<endl;
        }

    node * left_node(node *ptr1,node *ptr2)
       {

         if (ptr1->left==NULL)
             {
               // now we have found the exact space to be empty with us//
               cout<<"It looks like we have a vacant space in the left"<<endl;
               ptr1->left=ptr2;
               // we have put the node now //
               return ptr1;
             }


          if (ptr1->left!=NULL)
             {
               ptr1=ptr1->left;
               // it means there is an element lying on the left of the node//
               // we will have to give the choice to the user
               cout<<"sorry the left place of the current node is full where should we move next"<<endl;
               cout<<"Move Right"<<endl;
               cout<<"Move Left"<<endl;
               char choice;
               cin>>choice;
               if (choice=='L')
                  {
                    ptr1=left_node(ptr1,ptr2);
                  }
               if (choice=='R')
                  {
                    ptr1=right_node(ptr1,ptr2);
                    // this process will be working recursively //
                  }

             }
          return ptr1;
       }
    node *right_node(node *ptr1,node*ptr2)

        {
          if (ptr1->right==NULL)
              {
                // now we have found the exact space to be empty with us//
                cout<<"It looks like we have the vacant space in the right";
                ptr1->right=ptr2;
                // we have put the node now //
                return ptr1;
              }


           if (ptr1->right!=NULL)
              {
                ptr1=ptr1->right;
                // it means there is an element lying on the left of the node//
                // we will have to give the choice to the user
                cout<<"sorry the right place of the current node is full where should we move next"<<endl;
                cout<<"Move Right"<<endl;
                cout<<"Move Left"<<endl;
                char choice;
                cin>>choice;
                if (choice=='L')
                   {
                     ptr1=left_node(ptr1,ptr2);
                   }
                if (choice=='R')
                   {
                     ptr1=right_node(ptr1,ptr2);
                     // this process will be working recursively //
                   }

              }
           return ptr1;
        }
      };



int main()
  {
  // this is the program related to trees
  // first we will be creating the nodes of the tree
  int root_val;
  cout<<"Enter the value of the root node";
  cin>>root_val;
  // now we will be creating the root node in the main function //
  node *root=new node;
  node*mainroot=root;

  root->create_node(root_val);
  // now our root node is created //
  int info=0;
  cout<<"Enter the information for the upcoming nodes"<<endl;
  cin>>info;
  while (info>0)
     {
       // we will be taking the inputs till the time we get a negative input from the user itself //
       // we will be adding the tree nodes as per the demand of the user //
       node *node_to_be_sent=new node;
       node_to_be_sent->create_node(info);
       // now our node is ready and this node is after the root node that is avaialble with us //
       char choice;
       cout<<"Where do you want to enter this node after the previous node"<<endl;
       cout<<"Remember we will be adding the roots from the start"<<endl;
       cin>>choice;
       if (choice=='L')
          { // now we will be entering  the node to the left hand side of the root //
            node_to_be_sent=node_to_be_sent->left_node(root,node_to_be_sent);
          }
       if (choice=='R')
         {
            // the node will now be entered to the  right side of the main root node//
            node_to_be_sent=node_to_be_sent->right_node(root,node_to_be_sent);
         }
      // now we will be again entering the value of the new nodes as per the loop in the starting //
      cout<<"Enter the information once again"<<endl;
      cin>>info;


     }
// now we have constructed our tree//
//lets get some of the outputs to check whether the nodes are working in the right direction or not //node
///root->display_values(root);
// if we look at the above commented statement, we can see that the tree is working fine //
//now we will looking for the  pre order traversal of the tree //

cout<<"Now we will look at the pre order traversal of the tree"<<endl;
cout<<"It is given using the following Formula Root Left Right"<<endl;

root->pre_order(root);
  }
