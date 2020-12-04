#include <iostream>
#include <string>
#include <vector>


using namespace std;


void selectionSort(vector<int> nums) {
		//will flip the smallest untouched value anywhere in array based on where it belongs
		int tempSwi;
		
		for(int i = 0; i < nums.size() - 1; i++) {
			int temp = i;
			for(int j = i + 1; j < nums.size(); j++) {
				if(nums.at(j)  < nums.at(temp))
					temp = j;
			    
			}
            tempSwi = nums.at(temp);
			nums.assign(temp, nums.at(i));
			nums.assign(i, tempSwi);
		}
	}

   
    
    
int main(){
    vector<int> v;
    
    v.push_back(0);
    v.push_back(20);
    v.push_back(5);
    v.push_back(19);
    v.push_back(23);
    v.push_back(1);
    selectionSort(v);
    for(int i : v){
        cout << i << ", ";
    }
    cout << "\n";


    return 0;
}