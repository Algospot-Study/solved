#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> dictionary;     // 최종 결과물을 저장할 곳 (위상정렬 결과 저장할 곳)
vector<bool> isVisited;      // 방문했는지 여부 확인

vector<bool> isVisited_2;
bool isCycle;

vector<vector<int>> graph;

vector<string> inputVal;    // // 여기 입력받은 다

void dfs(int k){ // k ? <-- 현재 vertex
    isVisited[k] = true;
    isVisited_2[k] = true;
    for(int i = 0; i < graph[k].size(); i++){
        if(isVisited_2[k])  //사이클 생성이 됐단것을 의미한다.
        {
            isCycle = true; //사이클 생성됐다고 알리고 dfs 종료
            return;
        }
        if(!isVisited[i]){
            dfs(i);
            // 사이클을 찾을 수 있어야함c
        }
    }
    dictionary.push_back(k);
}

void dfsAll(){
    for(int i =0; i < graph.size(); i++){
        if(isCycle) return;                   // 사이클이 없으면 계속 탐색
        if(!isVisited[i])
            dfs(i);
        isVisited_2 = vector<bool>(26, false);
    }
}
// 시작 인덱스, 마지막 인덱스 (inputVal 에서 인덱스를 가리킬 것들)
// 예를 들어서
// kk kgo kgl hp hq
// 첫단어만 같은것들을 찾아요
// 0~2
// findAndMakeGraph(int startIdx, int endIdx)
// findAndMakeGraph(0, 2)
// global inputVal이니까 넘겨주진 않음, index는 계속 원래 inputVal에 맞춰서 생각
// 같은 단어들이니까 한 인덱스씩 넘겨요
// 다음단어들만 쳐다보면
// k go gl
// k, g는 다르니까 일단 그래프를 만드는게 베이스 케이스?
// go gl 같으니까
// findAndMakeGraph(1, 2)
// 다음인덱스로 넘기고
// o l
// 다르니까
// o -> l 그래프 작성
//
void findAndMakeGraph(int startIdx, int endIdx, int toShow){
    // string으로 넘어오는데 그냥 지금 스트링을 짜르질 않으니까 toShow가지고
    // inputVal[0][0], inputVal[1][0]
    // 두 단어가 같아서 또 호출되고 다음 인덱스를 바라볼 때
    // inputVal[0][1], inputVal[1][1]
    // 처음 호출될 경우는
    // findAndMakeGraph(0, inputVal.size(), 0)
    int last = startIdx;
    for(int i = startIdx+1; i < endIdx; i++){
        // 같으면 넘겨요 계속
        // 다르면 거기서 다른 findAndMakeGraph
        if(inputVal[last][toShow] == inputVal[last][toShow]){
            ++last;
        }else {
            // 지금 바라보는 포인터의 글자가 같았던 것들 끼리는 다시 find호출
            findAndMakeGraph(startIdx, last, toShow+1);
            // 마지막 바라보던 글자와 지금 바라보는 글자가 다르니까
            // 여기서 일단 그래프 생성
            graph[last][i] = 1;
        }
    }
}


int main() {
    int testCase;
    cin >> testCase;
    while(testCase--){
        // 그래프 초기화
        graph.clear();  //되나?
        // isVited 초기화
        isVisited_2 = vector<bool>(26, false);
        int wordLength;
        isCycle = false;

        cin >> wordLength;
        inputVal.clear();
        while (wordLength--){
            string tmpInput;
            cin >> tmpInput;
            inputVal.push_back(tmpInput);
        }

        //그래프를 만들고
        // 첫번째 단어들을 먼저 가지고 시작
        // 첫번째 단어들을 먼저 비교
        // 하나씩 포문? 돌면서??
        // 같은 단어끼리 비교하는걸로 들어가는데
        // 같은 단어끼리에서 또 다음 인덱스 쳐다보면서
        // 같은 단어인지 비교
        // 다르면 그래프에 집어넣기
        // 재귀호출해야될것 같은느낌?
        findAndMakeGraph(0,inputVal.size()-1, 0);
        dfsAll();
        //dfsAll호출
        if(isCycle)
            cout << "INVALID HYPOTHOSIS" << endl;
        else{
            for(int i = dictionary.size()-1; i >= 0 ; i--){
                cout << dictionary[i] << endl;
            }
        }
    }
}
