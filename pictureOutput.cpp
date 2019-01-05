#include <iostream>
#include <fstream>
#include <cstdlib>
#include "position.h"
#include "arraystack.h"
#include <iomanip>
using namespace std;
int size;
//int **pic;
arrayStack<position>* path; 
//bool findPath(int a[][]);
int main(){
    int x = 0;
    ofstream DFSimage;
    DFSimage.open("DFSIMAGE.txt");
    if(DFSimage.fail()){
        cout<< "DFS output file failed to open.\n";
        exit(1);
    }
    
    ofstream originalImage;
    originalImage.open("picOutput1.txt");
    
    if(originalImage.fail()){
        cout<< "output file failed to open.\n";
        exit(1);
    }
    
    double density;
    cout<< "Enter the density of the image.\n";
    cin>> density;
    if(density <0 || density >=1){
        density = .5;
    }

    cout<< "Enter the length of the side of the image.\n";
    cin>> size;
    if(size <5 || size > 20){
        size= 15;
    }
    int pic[size+2][size+2];
    //initialize wall around pic
    for(int i=0; i<=size+1; i++){
        pic[0][i]= pic[size+1][i]=0;
        pic[i][0]= pic[i][size+1]=0;
    }
    
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            double R;
            R= ((double) rand() / (RAND_MAX));
            if(R < density){
                pic[i][j] = 1;
            }
            else{
                pic[i][j]= 0;
            }
        }
    }
    for(int i=0;i<=size+1; i++){
        for(int j=0; j<=size+1; j++){
            originalImage << std::setw(3) <<  pic[i][j] << " " ;
        }
        originalImage<< endl;
    }
    int replacement=2;
    
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            if(pic[i][j]==1){
                //findPath(pic);
    path = new arrayStack<position>;
    pic[i][j]=replacement;
    position offset[4];
    offset[0].row= 0; offset[0].col = 1;//right
    offset[1].row = 1; offset[1].col=0;//down
    offset[2].row=0; offset[2].col=-1;//left
    offset[3].row=-1;offset[3].col=0;//up
    
    int option = 0;
    int lastoption =3;
    position here;
    here.row=i;
    here.col=j;
    while(here.row != size+1 || here.col != size+1){
    //search for other '1's to its neighbors
    int r, c;
    while(option <=lastoption){
        r= here.row + offset[option].row;
        c= here.col + offset[option].col;
        if(pic[r][c]==1){
            break;
        }
        option++;
    }
    //was neighbor 1 found?
    if(option <=lastoption){
        //move to pic[r][c]
        path->push(here);
        here.row=r;
        here.col=c;
        pic[r][c]=replacement;
        option=0;
    }
    else{
        //no neighbor found w 1
        if(path->empty()){
            replacement++;
            break;
        }
        position next= path->top();
        path->pop();
        if(next.row == here.row){
            option = 2 + next.col - here.col;
        }
        else{
            option= 3+ next.row-here.row;
        }
        here= next;
        
        replacement++;
        replacement--;
    }
    
    }
            }
            else{
                continue;
            }

        }
    }
    
    for (int x=0; x<=size+1; x++){
        for(int y=0; y<=size+1; y++){
            DFSimage << std::setw(3) << pic[x][y] << " ";
        }
        DFSimage<< endl;
    }
return 0;
}
/*
bool findPath(int a[][]){
    int replacement = 2;
    path = new arrayStack<position>;
    position offset[4];
    offset[0].row= 0; offset[0].col = 1;//right
    offset[1].row = 1; offset[1].col=0;//down
    offset[2].row=0; offset[2].col=-1;//left
    offset[3].row=-1;offset[3].col=0;//up
    
    int option = 0;
    int lastoption =3;
    position here;
    here.row=1;
    here.col=1;
    while(here.row !=size || here.col != size){
    //search for other '1's to its neighbors
    int r, c;
    while(option <=lastoption){
        r= here.row + offset[option].row;
        c= here.col + offset[option].col;
        if(pic[r][c]==1){
            break;
        }
        option++;
    }
    //was neighbor 1 found?
    if(option <=lastoption){
        //move to pic[r][c]
        path->push(here);
        here.row=r;
        here.col=c;
        pic[r][c]=replacement;
        option=0;
    }
    else{
        //no neighbor found w 1
        if(path->empty()){
            replacement++;
            return false;
        }
        position next= path->top();
        path->pop();
        if(next.row == here.row){
            option = 2 + next.col - here.col;
        }
        else{
            option= 3+ next.row-here.row;
        }
        here= next;
    }
    }
    replacement++;
    return true;
}
  */  

            