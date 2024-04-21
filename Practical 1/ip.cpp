#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int a,b;
    string ip;
    string arr[6];
    cout<<"Enter the Ipv4 address string: ";
    cin>>ip;
    int j = 0;
    int len = 1;        //1

    for(int i = 0; i<ip.length(); i++){
        if(ip[i]!='.'){
            arr[j] = arr[j] + ip[i];
        } else{
            j++;
            len++;
        }
    }
    


    int input;
    do
    {
    cout<<endl;
    cout<<"1 : Checking leading zeros \n2 : For checking range and integer values\n3 : Checking exact cell number of ip \n";
    cout<<"4: for checking if ip address is separated by dot only \n5 : Finding ip address class \n6 : Checking if ip address is Special"<<endl;
    cout<<"7 : Exit \n8 : Enter new ip address"<<endl;
    cout<<endl;
    cout<<"Enter input: ";
    cin>>input;
    
        switch (input){
            case 1:
                a = 0;
                for(int j = 0; j<4; j++){
                    if(arr[j][0] == '0'){
                        cout<<"Error: Leading zeros detected  "<<endl;      //arr[j]
                        a++;
                    }
                }
                if(a == 0){
                    cout<<"No leading zeros detected"<<endl;
                }
                break;

            case 2:
                a = 0;
                b = 0;
                for(int j = 0; j<4; j++){
                    try{
                        int value = stoi(arr[j]);
                        if(!(value>0 && value<255)){
                        cout<<"ERROR: "<<value<<" should be between the range of 0-255 "<<endl;
                        a++;
                        break;
                    }
                    } catch(exception e){
                        cout<<"ERROR: The entered Ipv4 does not contain only integer values"<<endl;
                        b++;
                        break;
                    }
                }
                if(a==0) cout<<"No range error. "<<endl;
                if(b==0) cout<<"The cell value have only integer values."<<endl;
                break;

            case 3:
                a = 0;
                if(len != 4){
                    a++;
                    cout<<"ERROR: The Ip address should have exactly 4 cells"<<endl;
                }
                if(a==0 && arr[3].length()>=1) cout<<"Ip address has exactly 4 cells"<<endl;

                else cout<<"Invalid ip"<<endl;
                break;

            case 4:
                a = 0;
                for(int i = 0; i<ip.length(); i++){
                    if(!(int(ip[i]) == 46 || int(ip[i])>47 && int(ip[i])<58 )){ 
                        a++;
                        cout<<"ERROR: Each Ip cell value should be seperated by dot only Error: "<<ip[i]<<endl; 
                    }
                }
                if(a == 0) cout<<"Each ip cell is only seperated by dot"<<endl;
                break;

            case 5:
                if(stoi(arr[0]) >= 0 && stoi(arr[0])<127)
                    cout<<"Class A"<<endl;
                if(stoi(arr[0]) > 127  && stoi(arr[0])<=191)
                    cout<<"Class B"<<endl;
                if(stoi(arr[0]) > 191  && stoi(arr[0])<=223)
                    cout<<"Class C"<<endl;
                if(stoi(arr[0]) > 223  && stoi(arr[0])<=239)
                    cout<<"Class D"<<endl;
                if(stoi(arr[0]) >= 240  && stoi(arr[0])<=255)
                    cout<<"Class E"<<endl;
                
                break;

            case 6:
                if(ip == "0.0.0.0"||ip == "127.0.0.0"||ip == "127.0.0.1"||ip == "224.0.0.0"||ip == "169.254.0.0"||ip == "192.0.0.0"||ip == "255.255.255.255")
                    cout<<"This is a special ip address"<<endl;
                else    
                    cout<<"It is not a special ip address"<<endl;

                break;
            case 7:
                cout<<"Exiting the program..";
                break;

            case 8:
                cout<<"Enter new ip ";
                cin>>ip;
                break;
            default:
                cout<<endl;
                break;
        }
    }while(input!=7);
    
    return 0;
}