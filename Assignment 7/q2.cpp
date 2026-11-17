
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
    string clearGroups(string board)
    {
        while(true)
        {
            bool removed = false;

            for(int i = 0; i < board.length();)
            {
                int end = i + 1;

                while(end < board.size() && board[end] == board[i])
                {
                    end++;
                }

                if(end - i >= 3)
                {
                    board.erase(i, end - i);
                    removed = true;
                    break;
                }

                i = end;
            }

            if(!removed)
                return board;
        }
    }

    string makeKey(string board, vector<int>& hand)
    {
        string key = board + "#";

        for(int i = 0; i < 26; i++)
        {
            key += to_string(hand[i]) + ",";
        }

        return key;
    }

    int findMinimum(string board, vector<int>& hand,
                    unordered_map<string, int>& memo)
    {
        board = clearGroups(board);

        if(board.empty())
            return 0;

        string key = makeKey(board, hand);

        if(memo.find(key) != memo.end())
            return memo[key];

        int answer = INT_MAX;

        for(int i = 0; i < board.length();)
        {
            int end = i + 1;

            while(end < board.size() && board[end] == board[i])
            {
                end++;
            }

            int needed = 3 - (end - i);
            int color = board[i] - 'A';

            if(needed > 0 && hand[color] >= needed)
            {
                hand[color] -= needed;

                int remaining = findMinimum(
                    board.substr(0, i) + board.substr(end),
                    hand, memo
                );

                if(remaining != -1)
                    answer = min(answer, needed + remaining);

                hand[color] += needed;
            }

            i = end;
        }

        memo[key] = (answer == INT_MAX) ? -1 : answer;

        return memo[key];
    }

public:
    int boardGame(string board, string handString)
    {
        vector<int> hand(26, 0);

        for(int i = 0; i < handString.length(); i++)
        {
            hand[handString[i] - 'A']++;
        }

        unordered_map<string, int> memo;

        return findMinimum(board, hand, memo);
    }
};

int main()
{
    Solution s;

    cout << "Minimum number of balls to insert: ";

    cout << s.boardGame("WWRRBBWW", "WRBRW") << endl;

    return 0;
}
