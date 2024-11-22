#include <iostream>
#include<cmath>
using namespace std;
bool ok (int q[], int c){
  int newMan, newWoman, currentMan, currentWoman;
  static int mp[3][3] = { {0,2,1},
                          {0,2,1},
                          {1,2,0}
};
  static int wp[3][3] = { {2,1,0},
                          {0,1,2},
                          {2,0,1}
};

  for(int i = 0; i < c; i++){
    newMan = c;
    newWoman = q[c];
    currentMan = i;
    currentWoman = q[i];
  //Make sure no 2 woman likes the same man.
  if(q[c] == q[i]) {
    return false;
  }
    //Checks the prefrences of currentMan and currentWoman, to make sure neither of them likes the newMan or the newWoman more than eachother.
  if ((mp[currentMan][currentWoman]>mp[currentMan][newWoman]) && (wp[newWoman][currentMan]<wp[newWoman][newMan])){
    return false;
  }
    //Checks the prefrences of the newMan and newWoman, to make sure neither of them likes the currentMan or thecurrentWoman more than eachother
  if ((mp[newMan][currentWoman]<mp[newMan][newWoman]) && (wp[currentWoman][newMan]<wp[currentWoman][currentMan])) {
    return false;
         }
     } 
  return true;
}

void print(int q[3]){
  static int S = 0;
  cout << "Solution #" << ++S << endl;
  cout << "Man" << " " << "Woman" << endl;
  for(int i = 0; i < 3; i++){
    cout << i << "   " << q[i] << endl;
  }
}
int main() {
  int q[3] = {};
  int c = 0;

  while(c>=0){
    c++;
    if (c==3){
      print(q);
      c--;
    }
    else {
      q[c] = -1;
    }
    while(c>=0){
      q[c]++;
      if(q[c]==3){
        c--;
      }
      else if (ok(q,c)) {
     
        break;
         }
       }
     }
  return 0;
}