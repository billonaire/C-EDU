// 어떤 것이 반복적인가, 일반화할 수 있는가


//bool larger_than_42(int x) {
//	return x > 42;	// 42 이상 수만 찾음
//}
//
//bool odd(int x){ 
//	return x % 2;
//}
//
//void find(vector<int>& v) {
//	auto p = find_if(v.begin(), v.end(), odd); // 홀수만 서치
//	if(p != v.end())
//	{ }
//}

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;


void print(vector<int>& v) {
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int start(vector<int>& v) {

	int memory = 0;

	switch (v.back()) {
	case 1:
		memory = 1;
		break;
	case 2:
		memory = 2;
		break;
	case 3:
		memory = 3;
		break;
	case 4:
		memory = 4;
		break;
	case 5:
		memory = 5;
		break;
	case 6:
		memory = 6;
		break;
	case 7:
		memory = 7;
		break;
	case 8:
		memory = 8;
		break;
	case 9:
		memory = 9;
		break;
	case 10:
		memory = 10;
		break;
	case 11:
		memory = 11;
		break;
	case 12:
		memory = 12;
		break;
	case 13:
		memory = 13;
		break;
	}
	v.pop_back(); 

	return memory;
}


int main() {

	vector<int> deck = { 1,2,3,4,5,6,7,8,9,10,11,12,13,
						  1,2,3,4,5,6,7,8,9,10,11,12,13, 
						  1,2,3,4,5,6,7,8,9,10,11,12,13, 
						  1,2,3,4,5,6,7,8,9,10,11,12,13 };

	random_device rd;
	mt19937 seed(rd());
	shuffle(deck.begin(), deck.end(), seed);

	
	auto deck1 = vector<int>(deck.begin(), deck.end() - 48);
	auto deck2 = vector<int>(deck.begin()+4, deck.end() - 44);
	auto deck3 = vector<int>(deck.begin()+8, deck.end() - 40);
	auto deck4 = vector<int>(deck.begin()+12, deck.end() - 36);
	auto deck5 = vector<int>(deck.begin()+16, deck.end() - 32);
	auto deck6 = vector<int>(deck.begin()+20, deck.end() - 28);
	auto deck7 = vector<int>(deck.begin()+24, deck.end() - 24);
	auto deck8 = vector<int>(deck.begin()+28, deck.end() - 20);
	auto deck9 = vector<int>(deck.begin()+32, deck.end() - 16);
	auto deck10 = vector<int>(deck.begin()+36, deck.end() - 12);
	auto deck11 = vector<int>(deck.begin()+40, deck.end() - 8);
	auto deck12 = vector<int>(deck.begin()+44, deck.end() - 4);
	auto deck13 = vector<int>(deck.begin()+48, deck.end());


	while (true)
	{	
		static int memory = 13;

		switch (memory) {
		case 1:
			memory = start(deck1);
			break;
		case 2:
			memory = start(deck2);
			break;
		case 3:
			memory = start(deck3);
			break;
		case 4:
			memory = start(deck4);
			break;
		case 5:
			memory = start(deck5);
			break;
		case 6:
			memory = start(deck6);
			break;
		case 7:
			memory = start(deck7);
			break;
		case 8:
			memory = start(deck8);
			break;
		case 9:
			memory = start(deck9);
			break;
		case 10:
			memory = start(deck10);
			break;
		case 11:
			memory = start(deck11);
			break;
		case 12:
			memory = start(deck12);
			break;
		case 13:
			memory = start(deck13);
			break;
		}

		if (deck13.size() == 0) {
			printf("남은 카드 목록 \n \n");
			printf(" 1번째 덱: "); print(deck1);
			printf(" 2번째 덱: "); print(deck2);
			printf(" 3번째 덱: "); print(deck3);
			printf(" 4번째 덱: "); print(deck4);
			printf(" 5번째 덱: "); print(deck5);
			printf(" 6번째 덱: "); print(deck6);
			printf(" 7번째 덱: "); print(deck7);
			printf(" 8번째 덱: "); print(deck8);
			printf(" 9번째 덱: "); print(deck9);
			printf("10번째 덱: "); print(deck10);
			printf("11번째 덱: "); print(deck11);
			printf("12번째 덱: "); print(deck12);
			printf("13번째 덱: "); print(deck13);

			if (deck1.size() == 0 && deck2.size() == 0 && deck3.size() == 0 && deck4.size() == 0 &&
				deck5.size() == 0 && deck6.size() == 0 && deck7.size() == 0 && deck8.size() == 0 &&
				deck9.size() == 0 && deck10.size() == 0 && deck11.size() == 0 && deck12.size() == 0 &&
				deck13.size() == 0) {
				
				printf("\n \n Winer Winer Chiken Diner!!!!! \n \n");
			}
			break;
		}

	}
	
}


