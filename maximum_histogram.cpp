#include<iostream>
#include<deque>
using namespace std;

int maxRect(int input[],int length){
        deque<int> stack;

        int maxArea = 0;
        int area = 0;
        int i;

        for( i=0; i < length; i++ ){

            if(stack.empty() || input[stack.front()] <= input[i]){

                stack.push_front(i);

            }
            else{
                    while(input[stack.front()] > input[i]){
                    int top = stack.front();
                    stack.pop_front();

                      if(stack.empty()){
                       area = input[top] * i;

                    }

                    else{
                        area = input[top] * (i - stack.front() - 1);

                        }

                    if( i<length-1 )
                    {
                      i--;
                     }


                    if(area > maxArea){
                        maxArea = area;

                    }
                    if(stack.empty())break;
                }
            }
        }


        while( !stack.empty() ){


            int top = stack.front();

            stack.pop_front();

            if(stack.empty()){
                area = input[top] * i;
            }

            else{
                  area = input[top] * (i - stack.front() - 1);
                }

            if(area > maxArea){
                maxArea = area;

            }
        }
        return maxArea;
    }

int main(){
    int n,i;
    cin>>n;

    int ar[n];
    i=0;

    while(i<n){
      cin>>ar[i];
        i++;
    }
    cout<<maxRect(ar,n);

    return 0;
}
