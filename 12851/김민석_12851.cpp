#include<iostream>
#include <queue> //queue ����ϱ� ���Ͽ�
#include<algorithm>  //min �Լ� ��� ���Ͽ�
using namespace std;

#define MAXSIZE (int)1e5 + 1 //MAXSIZE ������ : 100001

int roads[MAXSIZE]; //array�� AMXSIZE ũ�⸸ŭ ������
int N, K; //�Է� ���� ����
queue<int> q; //BFS�� ���� queue ����
int result = 99999999; //min�� ������ ���Ͽ� result�� �ִ����� �ʱ�ȭ
int result_cnt = 0; //cnt ���

int main() {
	//����� �ð� ���̱� ���� �ʱ⼳��
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	//�Է°� ����
	cin >> N >> K;
	//�ʱ� ���� ������ 1�� �ʱ�ȭ
	roads[N] = 1;

	//bfs ����
	q.push(N);
	while (!q.empty()) {
		//queue���� ���� ó������ ����
		int curr = q.front();
		int currVal = roads[curr];
		q.pop();

		//����, ���簪�� ��ǥ���� K���,
		if (curr == K) {
			//���� result==currVal�̸�, ���� ���� �ð��� ����� ���� �� �ִٴ� ���̹Ƿ�
			if (result == currVal) {
				result_cnt++; //cnt�� ++�ϰ�
			}
			else { //�ƴ϶��
				result = min(result, currVal); //result �� ���� �����ϰ�
				result_cnt = 1; //cnt�� 1�� �ʱ�ȭ�Ѵ�.
			}
			continue; //continue�Ͽ� �Ʒ� ���� ���� ���
		}
		//������ 3���� ���̽��� ���Ͽ�
		// 1. �����̰� -1 �������� �� ��
		// ����, roads[curr - 1] == 0�̸� �ʱⰪ�� �� �������� ���� ó��
		// ��°��, roads[curr - 1]�� �� ũ�ٸ� ���� �� �ʿ䰡 �����Ƿ� ���
		if (roads[curr - 1] == 0 || roads[curr - 1] > currVal) {
			//���������� curr -1�� 0���ٴ� Ŀ���ϹǷ� ���� ó��
			if (curr - 1 >= 0) {
				roads[curr - 1] = currVal + 1; //�ð��ʸ� ���� + 1�� ����
				q.push(curr - 1); //queue�� ���� �� ����
			}
		}
		//2. �����̰� + 1 �������� ����
		if (roads[curr + 1] == 0 || roads[curr + 1] > currVal) {
			if (curr + 1 <= K) {
				roads[curr + 1] = currVal + 1;
				q.push(curr + 1);
			}
		}
		//3. �����̰� *2 �������� �����̵� �� ��
		if (curr * 2 < MAXSIZE && (roads[curr * 2] == 0 || roads[curr * 2] > currVal)) {
			roads[curr * 2] = currVal + 1;
			q.push(curr * 2);
		}
	}

	//���������� ������ش�.. endl ��ſ� �ð��� �� ���̱� ���Ͽ� '\n' ���
	std::cout << result -1  << '\n' << result_cnt;

	return 0;
}