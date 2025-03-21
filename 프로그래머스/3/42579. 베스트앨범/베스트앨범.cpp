#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_multimap<string, pair<int, int>> playInfo;    // pair는 고유번호+재생횟수
    unordered_map<string, int> totalPlayed;
    
    for(int i=0;i<genres.size();++i){
        playInfo.insert({genres[i], {i, plays[i]}});
        totalPlayed[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> sortedTotalPlayed;
    sortedTotalPlayed.reserve(totalPlayed.size());
    for(const auto& total : totalPlayed){
        sortedTotalPlayed.push_back(total);
    }
    sort(sortedTotalPlayed.begin(), sortedTotalPlayed.end(),
         [](const pair<string, int>& a, const pair<string, int>& b){
             return a.second > b.second;    // 플레이 순 기준 내림차순
         });
    
    vector<int> answer;
    
    for(const auto& total : sortedTotalPlayed){
        auto range = playInfo.equal_range(total.first); // 장르에 해당하는 곡들
        vector<pair<int, int>> songs;   // 고유번호 + 재생횟수
        songs.reserve(playInfo.count(total.first));
        for(auto itr = range.first; itr != range.second; ++itr){
            songs.push_back(itr->second);   // 해당 장르의 고유번호+재생횟수를 뽑아온다
        }
        sort(songs.begin(), songs.end(),
             [](const pair<int, int>& a, const pair<int, int>& b){
                 if (a.second == b.second)
                     return a.first < b.first;  // 같은 재생횟수끼리는 고유번호 오름차순
                 return a.second > b.second;    // 재생횟수 내림차순
             });
        for(int i=0;i<2 and songs.size() > i;++i){
            answer.push_back(songs[i].first);
        }
    }
    
    return answer;
}