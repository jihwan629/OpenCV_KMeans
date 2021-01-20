# OpenCV K-Means 이미지 분할 프로젝트


<br>

> [Visual Studio에서 OpenCV 설치하기](https://diyver.tistory.com/50)  <br>

<br>
<br>

## 목표

> K-Means 알고리즘으로 이미지 분할  <br>
> 최적의 클러스터 개수 구하기  <br>

<br>
<br>

 ## K-Means 알고리즘

 <img src="https://miro.medium.com/max/1050/1*dPm3eK6_mYhRTG6ik5YbLQ.png" width="500"/>
 
 <br>
 
[사진 출처](https://medium.com/@nsh235482/k-means-clustering-6ab85a2a32ad)

<br>
<br>

> 주어진 데이터를 k개의 클러스터로 묶는 알고리즘 <br>


<br>
<br>

## 입력
 
 <img src="https://user-images.githubusercontent.com/31186176/105198583-21bee700-5b81-11eb-8141-5aa5e0eba15c.PNG" width="300"/>
 
<br>
<br>

 ## 결과
 
 <img src="https://user-images.githubusercontent.com/31186176/105198692-43b86980-5b81-11eb-93ef-2dcdbbaf0210.PNG" width="300"/>
 
 > [Elbow 기법](https://m.blog.naver.com/PostView.nhn?blogId=samsjang&logNo=221017639342&proxyReferer=https:%2F%2Fwww.google.com%2F) 사용<br>
 > 클러스터 내 오차 제곱합이 급격히 변하는 부분(elbow)를 최적 클러스터 개수로 결정<br>
 
 <br>
 
 <img src="https://user-images.githubusercontent.com/31186176/105198732-4fa42b80-5b81-11eb-807a-925ed234f7aa.PNG" width="300"/>
 
 > 최적 클러스터 개수 k = 6 <br>
 
 <br>
 
 <img src="https://user-images.githubusercontent.com/31186176/105198765-5894fd00-5b81-11eb-9d60-cb29bff72a7a.PNG" width="600"/>

<br>
<br>
