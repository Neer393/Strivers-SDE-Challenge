#include <bits/stdc++.h> 
int romanToInt(string s) {
    int ans=0;
        int prevvalue=0;
        if(s[0]=='M'){
            ans+=1000;
            prevvalue=1000;
        }
        else if(s[0]=='D'){
            ans+=500;
            prevvalue=500;
        }
        else if(s[0]=='C'){
            ans+=100;
            prevvalue=100;
        }
        else if(s[0]=='L'){
            ans+=50;
            prevvalue=50;
        }
        else if(s[0]=='X'){
            ans+=10;
            prevvalue=10;
        }
        else if(s[0]=='V'){
            ans+=5;
            prevvalue=5;
        }
        else{
            ans+=1;
            prevvalue=1;
        }
        for(int i=1;i<s.length();i++){
            if(s[i]=='M'){
                if(prevvalue>=1000){
                    ans+=1000;
                }
                else{
                    ans+=1000-(2*prevvalue);
                }
                prevvalue=1000;
            }
            else if(s[i]=='D'){
                if(prevvalue>=500){
                    ans+=500;
                }
                else{
                    ans+=500-(2*prevvalue);
                }
                prevvalue=500;
            }
            else if(s[i]=='C'){
                if(prevvalue>=100){
                    ans+=100;
                }
                else{
                    ans+=100-(2*prevvalue);
                }
                prevvalue=100;
            }
            else if(s[i]=='L'){
                if(prevvalue>=50){
                    ans+=50;
                }
                else{
                    ans+=50-(2*prevvalue);
                }
                prevvalue=50;
            }
            else if(s[i]=='X'){
                if(prevvalue>=10){
                    ans+=10;
                }
                else{
                    ans+=10-(2*prevvalue);
                }
                prevvalue=10;
            }
            else if(s[i]=='V'){
                if(prevvalue>=5){
                    ans+=5;
                }
                else{
                    ans+=5-(2*prevvalue);
                }
                prevvalue=5;
            }
            else{
                if(prevvalue>=1){
                    ans+=1;
                }
                else{
                    ans+=1-(2*prevvalue);
                }
                prevvalue=1;
            }
        }
        return ans;
}
