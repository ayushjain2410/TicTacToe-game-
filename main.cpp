//creating tic tac toe project
#include <iostream>
using namespace std;
//global variables declarations
char arr1[9]={'1','2','3','4','5','6','7','8','9'};
int no_of_games;
string player1;
string player2;
char symbol1='O';
char symbol2='X';
string z=" ";
char arr[9]={};

int  credentials(){
        cout<<"number of games you want to play :";
        cin>>no_of_games;
        cout<<"player 1 please enter your name  :";
        cin>>player1;
        cout<<"player 2 please enter your name  :";
        cin>>player2;
        cout<<player1<<"      :   "<<symbol1<<endl;
        cout<<player2<<"      :   "<<symbol2<<endl;
        return no_of_games;
}
void overall_result(string overall[],int num){
    int count1=0;
    int count2=0;
    cout<<"\n\n\n\n\n\n\n\n"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t overall result is as follows "<<endl;
    cout<<"------------------------------------------------------------------------\n";
    for(int x=0;x<num;x++){
        if (overall[x]==" "){
          cout <<"match is draw"<<endl;
        cout<<"------------------------------------------------------------------------\n";
        }else{
            cout <<"result of round "<<x+1<<" is "<<overall[x]<<endl;
        cout<<"------------------------------------------------------------------------\n";

        }

        if(overall[x]==player1){
            count1+=1;

        }else if(overall[x]==player2){
            count2+=1;
        }
    }
    if(count1>count2){
        cout<<"------------------------------------------------------------------------\n";
        cout<<"\n\n\n\n overall winner is "<<player1<<endl;
        cout<<"------------------------------------------------------------------------\n";
        cout<<"overall score is "<<count1<<" : "<<count2<<endl;
    }else if(count1==count2){
        cout<<"------------------------------------------------------------------------\n";
        cout<<"\n\n\n\n overall match is draw "<<endl;
        cout<<"------------------------------------------------------------------------\n";
        cout<<"overall score is "<<count1<<" : "<<count2<<endl;


    }
    else{
        cout<<"------------------------------------------------------------------------\n";
        cout<<"\n\n\n\n overall winner is "<<player2<<endl;
        cout<<"------------------------------------------------------------------------\n";
        cout<<"overall score is "<<count1<<" : "<<count2<<endl;
    }



}
void round_end(int roundno){

    if(z==" "){
        cout<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"no winner of this round"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
    }else{
     cout<<endl;
     cout<<"------------------------------------------------------------------------"<<endl;
     cout<<"\t\t\t round "<<roundno+1 <<" ends with winner "<<z<<endl;
     cout<<"------------------------------------------------------------------------\n";

    }


}
class structure
{
    public:




    void struct1()
    {
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t"<<arr[0]<<"\t | \t"<<arr[1]<<"\t | \t"<<arr[2]<< endl;
        cout<<"\t\t\t\t\t | \t \t | \t"<<endl;
        cout<<"\t\t\t      -------------------------------------"<<endl;
        cout << "\t\t\t\t"<<arr[3]<<"\t | \t"<<arr[4]<<"\t | \t"<<arr[5]<< endl;
        cout<<"\t\t\t\t\t | \t \t | \t"<<endl;
        cout<<"\t\t\t      -------------------------------------"<<endl;
        cout << "\t\t\t\t"<<arr[6]<<"\t | \t"<<arr[7]<<"\t | \t"<<arr[8]<< endl;
        cout<<"\t\t\t\t\t | \t \t | \t"<<endl;
    }



};
class winner
{
public:
    void winner_combos()
    {
            if (arr[0]==arr[1] && arr[1]==arr[2])
            {
                if (arr[0]==symbol1)
                {
                    z=player1;

                }
                else
                {
                z=player2;
            }

        }
        else if(arr[3]==arr[4] && arr[4]==arr[5])
        {
            if (arr[3]==symbol1)
            {
                z=player1;
            }
            else
            {
                z=player2;
            }

        }
        else if(arr[6]==arr[7]&& arr[7]==arr[8])
        {
            if (arr[6]==symbol1)
            {
                z=player1;
            }
            else
            {
                z=player2;
            }

        }
        else if(arr[0]==arr[3] && arr[3]==arr[6])
        {
            if (arr[0]==symbol1)
            {
                z=player1;
            }
            else
            {
                z=player2;
            }

        }
        else if(arr[1]==arr[4] && arr[4]==arr[7])
        {
            if (arr[1]==symbol1){
                    z=player1;
                }else{
                    z=player2;
                }

        }else if(arr[2]==arr[5] && arr[5]==arr[8]){
            if (arr[2]==symbol1){
                    z=player1;
                }else{
                    z=player2;
                }

        }else if(arr[0]==arr[4] && arr[4]==arr[8]){
            if (arr[0]==symbol1){
                    z=player1;
                }else{
                    z=player2;
                }

        }else if(arr[2]==arr[4] && arr[4]==arr[6]){
            if (arr[2]==symbol1){
                    z=player1;
                }else{
                    z=player2;
                }

        }
};


};
class inputs : public structure,public winner{
public:
    int input(string which_player){
        int position;
        cout<<"enter your position "<<which_player<<" : ";
        cin>>position;
        return position;
    }
    void check(string which_player){
        int position1=input(which_player);
        if (arr[position1-1]=='O' || arr[position1-1]=='X'){
            cout<<"sorry cannot enter at that place (occupied)"<<endl;
            check(which_player);
        }else{
            if(which_player==player1){
                arr[position1-1]=symbol1;
            }else{
                arr[position1-1]=symbol2;
            }
            struct1();
            winner_combos();
        }

    }
};
class moves:public inputs{
    public:
    void initialization(){
      for (int j=0;j<9;j++){
            arr[j]=arr1[j];
        }

    }
    void move_of_players(){
        int i;
        for(int i=0;i<9;i++){

                if (i%2==0)
                {
                    check(player1);

                }
                else
                {
                    check(player2);
                }

                if(z!=" "){

                    break;
                }

        }if (i==9 && z==" "){
            cout<<"no winner for this round,match DRAW "<<endl;

        }
    }
};
int main()
{
    int number=credentials();
    string winners[number];
    moves obj1[number];

    for (int round_no=0; round_no<number; round_no++)
    {
        obj1[round_no].initialization();
        obj1[round_no].struct1();
        obj1[round_no].move_of_players();
        round_end(round_no);
        winners[round_no]=z;
        z=" ";
    }

    overall_result(winners,number);
    return 0;


}
