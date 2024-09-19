#include <iostream>
void triangular(int a) {
	int b = 1;
	int f = 1;
	while (b != 0){
		for (int i = 0; i < b; i++){
			std::cout<<"*"<<"";
		}
		std::cout<<std::endl;
		if (b == a){
			f = 0;
		}
		if (f == 1){
			b += 1;
		}
		else{
			b -= 1;
		}

		}
	}

int main(){
	int a;
	std::cout<<"Enter amount of triangular sides: "<<std::endl;
	std::cin>>a;
	triangular(a);
	return 0;
}