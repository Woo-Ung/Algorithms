#include<iostream>
#include <chrono>

using Comparison = bool (*)(int, int);

bool Asscending(int x, int y)
{
	return x > y;
}

bool Descending(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count;i++)
	{
		for (int j = i + 1; j < count;j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

//count를 n이라 하면,
//ㄴTime Complexity : 4*n*n
//ㄴSpace Complexity : 3 (매개변수는 space complexity제외)

//Complexity(복잡도)
//
//	Time Complexity
//		알고리즘의 시작 ~ 끝 소요 시간
//		수행 횟수
//
//	Space Complexity
//		알고리즘 도중에 사용되는 메모리를 측정
//		변수의 갯수

//Big O Notation
//컴퓨터의 성능이나 환경에 영향을 받지 않고, 입력의 갯수에 따라 정량화 측정
//
//1. 곱하기
//	변수를 제외한 상수는 무시
//2. 더하기
//	높은 차수만 고려(x : 1차, x ^ 2 : 2차)
//3. 숫자
//	무조건 1
//4. Worst case 계산
//	매개변수는 Space complexity에서 제외
//
//	점근법(asymtotic notation)
//
//O(n + 3) = O(n ^ 1 + 3 * n ^ 0) = O(n)
//O(2) = O(1)
//O(100000) = (1)




int main()
{
	const int ARRAY_COUNT{ 10 };
	int scores[ARRAY_COUNT]{ 20,10,40,15,30,70,90,80,50 };
	 
	//
	auto startTime = std::chrono::system_clock::now();
	Sort(scores, ARRAY_COUNT, Asscending);
	auto endTime = std::chrono::system_clock::now();
	//

	auto duration = endTime - startTime;

	std::cout << "Sort() runs : " << duration.count() << "ms" << std::endl;
}