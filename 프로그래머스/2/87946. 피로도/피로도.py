# Python 풀이 : Crush on Study
from itertools import permutations
def solution(k, dungeons):
    answer = -1
    save_k = k
    # k는 현재 피로도
    result = list(permutations(dungeons,len(dungeons)))    
    for idx in result:
        cnt = 0
        for need,use in idx:
            if save_k>=need: # 최소 피로도조건보다 같거나 큰지?
                save_k-=use
                cnt += 1
                answer = max(answer,cnt)

            else:
                save_k = k
                break

    return answer
