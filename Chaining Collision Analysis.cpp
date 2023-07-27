#include<iostream>
#include<cstdlib>         // I have used this library for the rand() function 
#define SIZE 1313         // I have defined this size for the Linked list chaining
#define SIZE_BST 1313     // I have defined this size for the BST chaining and AVL chaining

using namespace std;


class hashing{             // This class contains linear probbing           
    public:
 	int searches_attempt_linear;    	
    int total_searches_Probbing;
    int collisions_PROBBING;
    int size, value;
	long index; 
    int arr[1313];
    
  
    hashing(){
        size=1313;
        for(int i=0; i<size; i++){
            arr[i]=0;
        }
        collisions_PROBBING = 0;
        total_searches_Probbing = 0;
        searches_attempt_linear = 0;
    }
    
  
  
    void insert(long value){
        index = value % size; 
        if(arr[index]==0){
            arr[index]=value;
        }
        else{
        	collisions_PROBBING++;
            while(arr[index]!=0){
                index++;
                if(arr[index]==0){
                    arr[index]=value;
                    break;
                }
            }
        }
    }
    
  
  
    
	
	void search(long value){
		int count = 0;
        index = value % size;
        if(arr[index]==value){
        	total_searches_Probbing++;
        	count++;
        }
   
        else{
        	index++;
        	searches_attempt_linear++;
        	if(arr[index]==value){
			}
        }
        
    }
    
    
    
    
	
	void display(){
        for(int i=0; i<size; i++){
            cout<<"arr["<<i<<"] = "<<arr[i]<<endl;   
        }
        cout<<endl;
    }
    
    
    
    
    bool prime_check(int value){
       
	    if(value <= 1){
	       return false;
        }
        
        
		for(int i=2; i<=value/2; i++){
            if(value % i == 0){
		       return false;
		    }
        }
        
        return true;
   }

    
    
};






class node{        // This class contains linked list chaining
	public:
	int searches_attempt_linked;	
	int total_searches_Linked;	
	int collisions_LINK;	
    int index_list; 
	int data;
 	node* temp;
	node* next;
	node* new_node;
 	node* arr[SIZE];
	

	void link_chaining_NULL(){
		for(int i=0;i<SIZE;i++){
			arr[i]=NULL;
	    }
	    collisions_LINK = 0;
	    total_searches_Linked = 0;
	    searches_attempt_linked = 0;
	}
	
	
	
	
	void link_chaining_insert(int value){
	    new_node = new node();
		new_node->data = value;
		new_node->next = NULL;
		
		index_list = value % SIZE;
		
		if(arr[index_list] == NULL){
			arr[index_list] = new_node; 
	    }
	    
	    
	    else{
	        collisions_LINK++;	
	        temp = arr[index_list];
	        while(temp->next != NULL){
	         	temp = temp->next;
			}
		         
			temp->next = new_node;
		}
	}
	
	
	
	

 	void link_chaining_search(int value){
 		int count = 0;
 	
		 	   
 	    index_list = value % SIZE;
 		 
 		temp=arr[index_list];
 		
 		while(temp!=NULL){
 		
		    searches_attempt_linked++;
 		    
		 	if(temp->data == value){
 				count++;
 				total_searches_Linked++;
 	 		    break;
 			}
 			
 		    temp = temp->next;
 		     
 		}
	}
	
	
	
	

	void link_chaining_display(){
		for(int i=0; i<SIZE; i++){
			temp = arr[i];
			cout<<"Arr["<<i<<"]"; 
			while(temp!=NULL){                     // loop for displaying linked list chaining
			    cout<<"------>"<<temp->data;
				temp = temp->next;
			    
			}	
			cout<<"------>NULL"<<endl;
		    
		}
	}
	
	
	
    bool prime_check(int value){
       
	    if(value <= 1){
	       return false;
        }
        
        
		for(int i=2; i<=value/2; i++){
            if(value % i == 0){
		       return false;
		    }
        }
        
        return true;
   }

		  
}; 






class root{      // This class contains BST chaining 
	public:
	int searches_attempt_BST;	
	int total_searches_bst;
	int collisions_BST;	
	int data;
	int index_BST;
  	root* left;
	root* right;
	root* head;
	root* current;
	root* parent; 	
	root* new_node;
 	root* arr[SIZE_BST];
	
	
	
	void BST_chaining_NULL(){
		for(int i=0;i<SIZE_BST;i++){
			arr[i]=NULL;
		}
		total_searches_bst = 0;
		collisions_BST = 0;
	    searches_attempt_BST = 0;
	}
	
	
	
	void BST_insert(root* &temp, int value){
	    new_node = new root();
		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;
		
		index_BST = value % SIZE_BST;
	    
		if(arr[index_BST] == NULL){
			arr[index_BST] = new_node;
		}	
		
		else{
            collisions_BST++;			 
			temp = arr[index_BST];
			root* parent = NULL;
			root* current = temp;
		    while(current != NULL){
		    	parent = current;
			 	
				 if(value < current->data){
					current = current->left;
					if(current == NULL){
						parent->left = new_node;
						break;
					}
			   }
			   else if(value > current->data){
			   	    current = current->right; 
				    if(current == NULL){
				    	parent->right = new_node;
				    	break;
					}	      
			    }
			    else{
	 		    	break;
				}
			}
 		}
	}
 	
	 
	  
	
	

	void BST_search(root* temp, int value){
		int count = 0;
		   
 	    index_BST = value % SIZE_BST;
 		 
 	    temp = arr[index_BST];
 		while(temp != NULL){
 			if(temp->data == value){
 				count++;
 				total_searches_bst++;
 		 	    break;
 			}
 			
			else if(value < temp->data){
				searches_attempt_BST++;
			 	temp = temp->left;
			} 
			
			else{
				searches_attempt_BST++;
			 	temp = temp->right;
			}
 		}
			   	
 		if(count == 0){
 	    }
 		
 	}
 	
 	

    void BST_display(root* temp){
    	
        for(int i=0; i<SIZE_BST; i++){
		    temp = arr[i];
			cout<<"Arr["<<i<<"]";
            
            while(temp!=NULL){
            	cout<<"------> "<<temp->data; 
                if(temp->left != NULL){
				    temp = temp->left; 
				}
				else{
					temp = temp->right;
				}  
            }
            cout<<"------> NULL"<<endl;
	    }
    }
 


};










class avl{      // This class contains AVL chaining 
	public:
	int searches_attempt_AVL;	
	int total_searches_AVL;
	int collisions_AVL;	
	int data;
	int index_AVL;
  	avl* left;
	avl* right;
	avl* head;
	avl* current;
	avl* parent; 	
	avl* new_node;
 	avl* arr[SIZE_BST];
	
	
	
	void AVL_chaining_NULL(){
		for(int i=0;i<SIZE_BST;i++){
			arr[i]=NULL;
		}
		total_searches_AVL = 0;
		collisions_AVL = 0;
	    searches_attempt_AVL = 0;
	}
	
	
	
	void balance(avl *temp){
        int b_factor_tree = 0;
        avl *current = temp;
    
        while(current != NULL){
            b_factor_tree = Balance_Factor(current);   // Total factore --> L H minus R H                   
        
            if(b_factor_tree > 1 && Balance_Factor(current->left) >= 0){    // Means that left subtree is heavy
                current = right_Rotation(current);
            } 
        
            else if(b_factor_tree < -1 && Balance_Factor(current->right) <= 0){   // Means that right subtree is heavy
                current = left_Rotation(current);
            }  
       
        
            else if(b_factor_tree > 1 && Balance_Factor(current->left) < 0){   // Here 2nd condition shows that right is heavy
                current->left = left_Rotation(current->left);
                current = right_Rotation(current);
            }
        
            else if(b_factor_tree < -1 && Balance_Factor(current->right) > 0){  // Here 2nd condition shows that left is heavy
                current->right = right_Rotation(current->right);
                current = left_Rotation(current);
            }

            if(current->left != NULL){          // temp ---> current
                current = current->left;        // parent ---> current 
            } 
        
            else{
                temp = current;
                break;
            }
        }
    }


 


    int Height_AVL(avl* temp){
    
        if(temp!=NULL){
            int left_tree_height = Height_AVL(temp->left);
            int right_tree_height = Height_AVL(temp->right);

            if(left_tree_height > right_tree_height){
                return (left_tree_height + 1);
           }
            else{
              return (right_tree_height + 1);
            }
        }
	}   




  
    int Balance_Factor(avl * temp){                             
        return Height_AVL(temp->left) - Height_AVL(temp->right);     // I adopted the formula of Height of left subtree
    }                                                                // - Height of right subtree 



    avl* right_Rotation(avl * temp){  //temp = y from the reference of figure which I learn from code with harry
        avl * x = temp -> left;
        avl * T2 = x -> right;
        x -> right = temp;
        temp -> left = T2;
        return x;
    } 


    avl* left_Rotation(avl * temp){   //temp = x from the reference of figure which I learn from code with harry 
        avl * y = temp -> right;
        avl * T2 = y -> left;
        y -> left = temp;
        temp -> right = T2;
        return y;
	}

 
	
	void AVL_insert(avl* &temp, int value){
	    new_node = new avl();
		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;
		
		index_AVL = value % SIZE_BST;
	    
		if(arr[index_AVL] == NULL){
			arr[index_AVL] = new_node;
		}	
		
		else{
            collisions_AVL++;			 
			temp = arr[index_AVL];
			avl* parent = NULL;
			avl* current = temp;
		    while(current != NULL){
		    	parent = current;
			 	
				 if(value < current->data){
					current = current->left;
					if(current == NULL){
						parent->left = new_node;
						break;
					}
			   }
			   else if(value > current->data){
			   	    current = current->right; 
				    if(current == NULL){
				    	parent->right = new_node;
				    	break;
					}	      
			    }
			    else{
	 		    	break;
				}
			}
 		}
 		
 		
 		balance(temp);
	}
 	
    	 
	  
	
	

	void AVL_search(avl* temp, int value){
		int count = 0;
		   
 	    index_AVL = value % SIZE_BST;
 		 
 	    temp = arr[index_AVL];
 		while(temp != NULL){
 			if(temp->data == value){
 				count++;
 				total_searches_AVL++;
 		 	    break;
 			}
 			
			else if(value < temp->data){
				searches_attempt_AVL++;
			 	temp = temp->left;
			} 
			
			else{
				searches_attempt_AVL++;
			 	temp = temp->right;
			}
 		}
			   	
 		if(count == 0){
 		 //  cout<<"Not Found !"<<endl;	
 	    }
 		
 	}
 	
 	

    void AVL_display(avl* temp){
    	
        for(int i=0; i<SIZE_BST; i++){
		    temp = arr[i];
			cout<<"Arr["<<i<<"]";
            
            while(temp!=NULL){
            	cout<<"------> "<<temp->data; 
                if(temp->left != NULL){
				    temp = temp->left; 
				}
				else{
					temp = temp->right;
				}  
            }
            cout<<"------> NULL"<<endl;
	    }
    }
    
     

 		
};



 



int main(){
	avl c;
	root b;
	node a;
    hashing obj;
    int x;
    int count = 0;
    int option;
    
    c.AVL_chaining_NULL();     // This function is for placing NULL at every index of AVL chaining   
    b.BST_chaining_NULL();     // This function is for placing NULL at every index of BST chaining   
    a.link_chaining_NULL();    // This function is for placing NULL at every index of linked list chaining
    
    avl* temp_2 = NULL;
    root* temp = NULL; 
    
    
    do{
       cout<<endl<<endl;
       cout<<"  ***** WELCOME to Chaining / Data Analysis Software ***** "<<endl;	 
       cout<<"               (Developed by TALHA KHALID)     "<<endl;    
       cout<<"What do you want to see ! "<<endl;
       cout<<"1. Analysis of 1000 Random Even Numbers"<<endl;
       cout<<"2. Analysis of 1000 Random Odd Numbers"<<endl;
	   cout<<"3. Analysis of 1000 Random Prime Numbers"<<endl;   	
	   cout<<"Select the Option / Number (Press 0 to exit) = ";
	   cin>>option;
	   
	   switch(option){
	   	case 1:
	    
        for(int i=0; i<1000; i++){
            x = rand() * 2;
        
	     	obj.insert(x);
        
            cout<<endl;
        
		    a.link_chaining_insert(x);
		   
		    cout<<endl;
		
	     	b.BST_insert(temp, x);
      
	  
	        cout<<endl;
		
	     	c.AVL_insert(temp_2, x);
        
		
		}   
	    
//		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
//		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
//	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
//	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
		
	 	
	 
	    for(int i=0; i<100; i++){
            x = rand();
     	    obj.search(x);
      
	        a.link_chaining_search(x);
	        cout<<endl; 
	    
	     
	        b.BST_search(temp, x);
	        cout<<endl; 
	        
	        c.AVL_search(temp_2, x);
	        cout<<endl; 
	        
	        
	        
	    } 
	    
//	    cout<<"Total Searches in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
//		cout<<"Total Searches in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
//	    cout<<"Total Searches in BST CHAINING =  "<<b.total_searches_bst<<endl;
//	    cout<<"Total Searches in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
//	    
//	    cout<<endl<<endl<<endl;
//	    
//	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
//	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
//	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
//	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
	    
	    
    
	    cout<<"     ------------------------------------------------------------------      "<<endl;
        cout<<endl<<endl;        
    
        cout<<endl;
        cout<<" ***** DISPLAYING FOR LINEAR PROBBING *****  "<<endl;
        cout<<endl<<endl;
	    obj.display();
    
    
        cout<<"  *****************************************************************************   "<<endl;
        cout<<endl<<endl;
    
	    cout<<"  ***** DISPLAYING FOR LINKED LIST CHAINING ***** "<<endl;
        cout<<endl<<endl;
	
	    a.link_chaining_display();
	    cout<<endl<<endl;
	
     	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR BST CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	b.BST_display(temp);
	
	    cout<<endl<<endl;
	
	
	 	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR AVL CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	c.AVL_display(temp_2);
	
	    cout<<endl<<endl;
	    
        cout<<endl<<endl;	    
	    
		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
		cout<<endl<<endl<<endl; 
	    
	    cout<<"Total Searches/Numbers Found in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
		cout<<"Total Searches/Numbers Found in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
	    cout<<"Total Searches/Numbers Found in BST CHAINING =  "<<b.total_searches_bst<<endl;
	    cout<<"Total Searches/Numbers Found in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
	    
	    cout<<endl<<endl<<endl;
	    
	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
		         
		         
	    break;		
	   	

 		
		 
		 
		case 2:
         
		for(int i=0; i<1000; i++){
            x = (rand() * 2) + 1;
        
	     	obj.insert(x);
        
            cout<<endl;
        
		    a.link_chaining_insert(x);
		   
		    cout<<endl;
		
	     	b.BST_insert(temp, x);
      
	  
	        cout<<endl;
		
	     	c.AVL_insert(temp_2, x);
        }   
	    
//		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
//		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
//	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
//	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
		
	 	
	 
	    for(int i=0; i<100; i++){
            x = rand();
     	    obj.search(x);
      
	        a.link_chaining_search(x);
	        cout<<endl; 
	    
	     
	        b.BST_search(temp, x);
	        cout<<endl; 
	        
	        c.AVL_search(temp_2, x);
	        cout<<endl; 
	    } 
	    
//	    cout<<"Total Searches in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
//		cout<<"Total Searches in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
//	    cout<<"Total Searches in BST CHAINING =  "<<b.total_searches_bst<<endl;
//	    cout<<"Total Searches in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
//	    
//	    cout<<endl<<endl<<endl;
//	    
//	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
//	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
//	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
//	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
	    
	    
    
	    cout<<"     ------------------------------------------------------------------      "<<endl;
        cout<<endl<<endl;        
    
        cout<<endl;
        cout<<" ***** DISPLAYING FOR LINEAR PROBBING *****  "<<endl;
        cout<<endl<<endl;
	    obj.display();
    
    
        cout<<"  *****************************************************************************   "<<endl;
        cout<<endl<<endl;
    
	    cout<<"  ***** DISPLAYING FOR LINKED LIST CHAINING ***** "<<endl;
        cout<<endl<<endl;
	
	    a.link_chaining_display();
	    cout<<endl<<endl;
	
     	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR BST CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	b.BST_display(temp);
	
	    cout<<endl<<endl;
	
	
	 	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR AVL CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	c.AVL_display(temp_2);
	
	    cout<<endl<<endl;
	    
	    
	    
	    
		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
		cout<<endl<<endl<<endl;
	    
	    cout<<"Total Searches/Numbers Found in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
		cout<<"Total Searches/Numbers Found in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
	    cout<<"Total Searches/Numbers Found in BST CHAINING =  "<<b.total_searches_bst<<endl;
	    cout<<"Total Searches/Numbers Found in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
	    
	    cout<<endl<<endl<<endl;
	    
	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
		         
        break;		
	   	
	   	
		case 3:
	
		for(int i=2; count < 1000; i++){
            x = rand();
           
		    if(obj.prime_check(x)){
		    	
		    	obj.insert(x);
                cout<<endl;
                a.link_chaining_insert(x);
		        cout<<endl;
		 	    b.BST_insert(temp, x);
                cout<<endl;
		      	c.AVL_insert(temp_2, x);
		      	
		      	count++;
		      	
         	}
 
      	}   
	    
//		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
//		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
//	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
//	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
//		
	 	
	 
	    for(int i=0; i<100; i++){
            x = rand();
     	    obj.search(x);
      
	        a.link_chaining_search(x);
	        cout<<endl; 
	    
	     
	        b.BST_search(temp, x);
	        cout<<endl; 
	        
	        c.AVL_search(temp_2, x);
	        cout<<endl; 
	        
	        
	        
	    } 
	    
//	    cout<<"Total Searches in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
//		cout<<"Total Searches in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
//	    cout<<"Total Searches in BST CHAINING =  "<<b.total_searches_bst<<endl;
//	    cout<<"Total Searches in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
//	    
//	    cout<<endl<<endl<<endl;
//	    
//	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
//	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
//	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
//	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
//	    
	    
    
	    cout<<"     ------------------------------------------------------------------      "<<endl;
        cout<<endl<<endl;        
    
        cout<<endl;
        cout<<" ***** DISPLAYING FOR LINEAR PROBBING *****  "<<endl;
        cout<<endl<<endl;
	    obj.display();
    
    
        cout<<"  *****************************************************************************   "<<endl;
        cout<<endl<<endl;
    
	    cout<<"  ***** DISPLAYING FOR LINKED LIST CHAINING ***** "<<endl;
        cout<<endl<<endl;
	
	    a.link_chaining_display();
	    cout<<endl<<endl;
	
     	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR BST CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	b.BST_display(temp);
	
	    cout<<endl<<endl;
	
	
	 	cout<<"  *****************************************************************************   "<<endl;
    
    	cout<<endl<<endl;
    
    	cout<<"  ***** DISPLAYING FOR AVL CHAINING ***** "<<endl;
    	cout<<endl<<endl;
    
    	c.AVL_display(temp_2);
	
	    cout<<endl<<endl;
		
		
		
		cout<<"Total Collisions in PROBBING CHAINING =  "<<obj.collisions_PROBBING<<endl;
		cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
	    cout<<"Total Collisions in BST CHAINING =  "<<b.collisions_BST<<endl;
	    cout<<"Total Collisions in AVL CHAINING =  "<<c.collisions_AVL<<endl;
		cout<<endl<<endl<<endl;
	    
	    cout<<"Total Searches/Numbers Found in LINEAR PROBBING CHAINING =  "<<obj.total_searches_Probbing<<endl;
		cout<<"Total Searches/Numbers Found in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
	    cout<<"Total Searches/Numbers Found in BST CHAINING =  "<<b.total_searches_bst<<endl;
	    cout<<"Total Searches/Numbers Found in AVL CHAINING =  "<<c.total_searches_AVL<<endl;
	    
	    cout<<endl<<endl<<endl;
	    
	    cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<obj.searches_attempt_linear<<endl;
	    cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
	    cout<<"Total Searches Attempted in BST CHAINING =  "<<b.searches_attempt_BST<<endl;
	    cout<<"Total Searches Attempted in AVL CHAINING =  "<<c.searches_attempt_AVL<<endl;
		         	
	   		
	    break;		
	   	
	   	default:
	   		cout<<"Please enter a valid option"<<endl;
	   }
	}
	while(option!=0);
    cout<<"Thanks for using my software"<<endl;	
	
	
	return 0;
	
	
}
    

