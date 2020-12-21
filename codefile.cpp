#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int target;
int return_count=0;
int solution(vector<int>);
void select_number(vector<int>&);
bool compare(int i,int j)
{
    return j<i;
}
int main(){
    vector<int> input_numbers(5);
    for(int i=0;i<input_numbers.size();i++) cin>>input_numbers[i];
    cin>>target;
    solution(input_numbers);
    return 0;
}

void select_number(vector<int> &numbers,int number){
    int roop=numbers.size();
    for(int i=roop-1;i>=0;i--){
        if(compare(numbers[i],number))numbers.pop_back();
        else break;
    }
    
}
void main_function(vector<int>& numbers,int number,int index){
    if(index==numbers.size()) return;
    for(int i=index;i<numbers.size();i++){
        number+=numbers[i];
        if(number==target) {
            return_count++;
        }
       main_function(numbers,number,i+1);
        number-=numbers[i];
    }
}

int solution(vector<int> numbers) {
    int answer = 0;
    int temp=0;
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<numbers.size();i++) temp+=numbers[i];
    target=(temp-target)/2;
    select_number(numbers,target);
    main_function(numbers,0,0);
    
    cout<<"return:"<<return_count<<endl;
    return answer;
}