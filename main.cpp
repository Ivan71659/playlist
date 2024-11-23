#include <iostream>

using namespace std;

class node {
  public: 
    string song;
    string artist;
    node* next;
    node* prev;  

    node(string song, string artist) {
      this->song = song;
      this->artist = artist;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class list {
  public: 
    node* head;
    node* tail;

    list () {
      head = nullptr;
      tail = nullptr;
    }

    void print () {
      cout << "\n";
      node* current = head;
      int counter = 1;
      while (current != nullptr){
        cout << counter << ") " << current->song << " " << current->artist << " ";
        current = current->next;
        counter += 1;
      }
      cout << "\n";
    }   

    void add_back (string song, string artist) {
      node* new_node = new node (song, artist);
      if(tail == nullptr) {
         head = new_node;
         tail = new_node;
      } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      } 
    }

    int get_size () {
      node* current = head;
      int size = 0;
      while(current != nullptr){
        size += 1; 
        current = current->next;
      }
      return size;
    }

    node* get_node (int position) {
      node* current = head;
      
      for(int i = 1; i < position; i++){
        current = current->next;
      }

      return current;
    }

    void remove_node (int position) {
      if(position == 1){
        node* new_head = head->next;
        delete head;
        head = new_head;

        if (head == nullptr) { 
          tail = nullptr; 
        } else { 
          head->prev = nullptr;
        }

        return;
      }
      
      int size = get_size ();
      if(position == size){
        node* new_tail = tail->prev;
        delete tail;
        tail = new_tail;

        if (tail == nullptr) {
          head = nullptr; 
        } else { 
          tail->next = nullptr;
        }

        return;
      }
      
      node*current = head;
      for(int i = 1; i < position; i++){
        current = current->next;
      }      
      
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
    }
};

int main () {
  list l;

  while (true) {
    int question1;
    cout << "\n1) view your entire playlist📼\n2) view your playlist individually📎\n3) add a song🪔\n4) delete a song🐦‍🔥\n5) exit🎋🍁🎍\n";
    cin >> question1;
    
    if(question1 == 1){
      l.print ();
    }
    
    if(question1 == 2){
      int position = 1;
      int size = l.get_size ();
      
      while (true) {
        node* current = l.get_node (position);
        cout << "\nCurrent: " << current->song << " " << current->artist << "\n";
        
        int question2;
        cout << "\n1) see next song🏪\n2) see previous song🎌\n3) go back to main menu😮\n";
        cin >> question2;
        
        if(question2 == 1){
          position += 1;
          if(position == size){
            position = 1;
          }
        }
        
        if(question2 == 2){
          position -= 1;
          if(position == 0){
            position = size;
          }
        }
        
        if(question2 == 3){
          break;
        }
      }
    }
  
    if(question1 == 3){
      string asker;
      cout << "\nwhat is your artist name?🟥⬜🟥👨‍🎨 ";
      cin >> asker;
      string asker2;
      cout << "what is your song name👨‍🎤👯 ";
      cin >> asker2;
      l.add_back(asker2,asker);  
    }
    
    if(question1 == 4){
      l.print();
      int deleterbeater;
      cout << "\nwhich song do you want to delete?💇‍♂️ ";
      cin >> deleterbeater;
      l.remove_node(deleterbeater);
    }
    
    if(question1 == 5){
      break;
    }
  }
}
