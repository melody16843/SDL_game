# 計程期末
# 第一部分
## 遊戲發想
最初的遊戲發想是想還原一刀斬(附上影片連結)，但是因為一刀斬中的動作其實非常複雜而且動畫很多，所以我們稍微將動作系統刪減到只剩下四個動作(垂直攻擊 水平攻擊 側身閃躲 蹲下閃躲)，但因為這個遊戲還是個動作遊戲，所以為了要讓動畫操作流暢我花了不少心思，剩下的遊戲機制基本都隨一刀斬。


遊戲機制的部分分成了人物動作 死亡判斷 地圖特效來介紹
## 人物動作
### 走路
走路是最一開始訂出來的，我們決定讓走路只有四幀，因為其他所有動作都是以走路衍伸出來的，若是走路幀數太多，那其他動作會連帶影響很大(後面會說明)而走路的圖片變化會由user class中一個private變數 frame來控制，此變數也在其他動作中產生很大作用
舉刀與收刀:因為一刀斬這個遊戲沒有所謂的血量，砍到一下就死了，所以攻擊模式的多樣化很重要，我們設計了兩種攻擊分別是垂直攻擊以及水平攻擊，而為了還原一刀斬的遊戲模式，我們設計舉刀與收刀兩個動作，如果要執行垂直攻擊就要先舉刀，水平攻擊則要先收刀，而這兩種動作在圖片呈現上會有一個問題:走路有四幀，在不同幀按下舉刀鍵user的腳會不一樣。為了增加遊戲的細緻度，舉刀跟收刀分別畫了16張圖片，而這16張圖片被存在兩個4x4的二維陣列中，因為舉刀與收刀的實作是一樣的後面以舉刀說明，以下為圖示:
在user中實作舉刀時，走路的frame是第一個index而第二個index才是舉刀實際動作執行的控制，這樣就可以解決走到每一幀揮刀動作會貼合腳的姿勢這點，而且這個也可以讓行進間能同時按下舉刀而走路的動畫還是流暢的。而舉刀與收刀還有一個點要實作，就是在舉刀與收刀的狀態要可以移動，如若看剛剛兩個二維陣列的03 13 23 33四張圖片就會發現這四張其實就可以構成舉著刀走路的動作，可以節省畫圖時間。

 
### 攻擊
就如同以上所說，要按下舉刀或收刀才能實行攻擊，而攻擊也為了配合腳的動作各畫了16張圖，實作的原理也與上面類似，但是攻擊的實作較舉刀收刀簡單一點，因為不能邊攻擊邊前進。攻擊的實作的難點在死亡判斷，這點會在死亡判斷說明。
### 閃躲
閃躲的實作其實很簡單，基本上跟走路的程式一樣，只是render的圖片換成閃躲的圖片而已
死亡判斷(對砍)
在死亡判斷的部分是用兩者在攻擊時的距離夠不夠近來判斷的，但是這樣的十座會造成一個問題，因為圖片是方形的而且負責美工的同學在畫人的時候沒有置中，所以在判斷的位子需要一點一點去慢慢調，但是這樣的判斷還是會照成一點點的誤差。死亡判斷還有另一個難點是，攻擊的動畫，因為當初本來要用攻擊案件是否被按下來判斷死亡，但是後來想到如果攻擊動畫已結束但是使用者還是按著攻擊鍵，這會造成bug，所以另外在user中設了一個private變數來偵測攻擊動畫是否結束。

## 地圖特效
當初我有設想要作故事系統，在故事進行到不同階段可以有不一樣的地圖特效，礙於時間的因素，最後決定使用地圖選擇來實作，而地圖特效執行的難點其實也就是死亡判斷的部分啦，圖片的形狀與人物或障礙物實際的形狀不一樣，所以只能透過位子判斷的參數調整來盡量作，但還是有些小問題(某些時候石頭看起來沒有砸到人)

## 美工設計
美工設計的部分因為考量到程式製作的難易度，我們決定人物的移動都以四禎為單位，而當初分到美工的同學的人物設計有點小悲劇，最後我們決定使用火柴人來當user(人物移動效果也不差就是了)。而背景的圖大部分是我與王同學製做，設計的初衷希望能還原一刀斬的遊戲風格，就是走一個日式的感覺。(基本上最特別的點應該就是滑鼠放到捲軸上卷軸會打開)
音效設計的部分我實作了兩個，一個是滑鼠放到捲軸上，卷軸打開的時候會有音效，還有在遊戲操作介紹的地方翻頁會有聲音，剩下是王同學做的。
以下為整體程式的繼承關係和分工:
 
(箭頭為繼承關係)


# 第二部份
## 結構圖

![](https://i.imgur.com/qXaGnvr.png)

### (A)	
主要的user的class和第二第三地圖的一些會導致死亡的障礙物obstacle
class也是由我寫的，最基底的LTexture也是主要由我寫，還有一部分的background也是我寫的，這幾個class的繼承關係在上方的圖是以大概介紹。
User 主要處理遊戲中兩位玩家的人物的動畫執行按鍵判斷以及死亡判斷
Deathobstacle主要處理障礙物的移動
Background主要處理主選單按鈕和各種背景圖片
LTexture 則是圖片的讀入與render
繼承層級:
deathobstacle  public繼承background(deathobstacle L8)，因為前者的性質基本上就是background但是他會有一些造成user死亡的功能，所以我沒有把他寫在background中而是另寫一個deathobstacle，而在background中一些與deathobstacle相關的參數放在protected給後者繼承(background L38)，而background中的函數主要都是判斷按鍵位子，需要提供給main使用，所以還是放在public的位子(background L10~35)，background中沒有private物件。
Friend:
因為deathobstacle會需要user的一些private參數來判斷死亡，所以將deathobstacle設為user的friend class(userdown L12)，還有在實作<<operator時將該operator設為friend function(userdown L13)。

Software reuse:
其實當初在設計這個遊戲的時候我有意圖做一個故事模式，(無奈組員…)在background class中的很多滑鼠位子的判斷其實是可以Reuse的，因為我當初設想作故事模式的話在轉場中可以設置一些動畫或是介紹，這些東西可以另寫一個class而Background class中的按鍵判斷以及render是可以重複使用的，但是因為最後沒有實作 而只有做了deathobstacle的繼承，所以在software reuse的部分才會看起來比較單薄。

### (B)
Constructor:
在user,background,LTexture中的constructor(userdown.cpp L26~35)(background.h L19~20)(LTexture.cpp L20~26)，主要做到就是參數的初始化，前兩個是確定物件在window中的render位子，在background的實作中有做了一個function overloading寫了兩個constructor，因為大部分的background皆為背景所以若constructor沒有傳入參數則設render位子為(0,0)，有傳入參數則使用member initializer來初始化位子參數。LTexture則是讀入圖片width height還有將 SDL_Texture指到NULL，也是初始化。
而在deathobstacle的constructor(deathobstacle.cpp L7~8)中運用了background中的一個public function (setvalue，因為main 中會需要改變此物件的位子來時做障礙物移動)，所以在deathobstacle的constructor就用了這個function(但其實直接設也沒差啦…)

Copy contructor:
在deathobstacle那邊 為了讓-operator程式碼較簡潔所以寫了一個copy contructor(deathobstacle L9)
Destructor:
在destructor的地方有一個點比較特別，原本我們的texture全部都寫在main中但後來我們將background的texture寫至background的public member中，可以節省在main中的程式碼，而且這樣圖片的render就可以直接透過background物件執行而不用使用extern把同樣的texture宣告放在background中，但因為這項操作讓background中會有一LTexture物件，所以在background的destructor中需要把他free掉。(background.cpp L4~8)

因為這個遊戲的物件創造基本上都在一開始就執行了，所以constructor跟destructor其實不會太複雜，而且也不會要一直讀入東西，所以也不太需要擔心記憶體的浪費。


### (C)
Operator overloading:
我主要製作了四個operator以下分項介紹
第一個是在deathobstacle中，因為障礙物就只有兩種，第一種的Bar物件有兩個在左側的要往右移動，而在右側的要往左移動，使用++來做到這功能，而因為兩個bar在移到中間前遊戲必定結束，所以以該物件所在的位置判斷他要往左還是往右，至於為甚麼不用--來實作往左就好了是因--我要留給rock下落速度的調整使用。(deathobstacle.cpp L11~37)(main.cpp L777~778)

第二個是在deathobstacle中的rock移動，當初我的設計是石頭的掉落速度應該要越來越快，所以實作了--和-兩種operator來控制石頭掉落速度，只是因為-來不及寫完，所以在demo中的石頭落下速度是固定的。(deathobstacle.cpp L38~48)(main.cpp L772)

第三種operator非常簡單，是在background中的render我們使用! Operator來表達render，單純只是因為在main中有很多位子出現render為了另程式看起來簡潔一點以及我們的方便而實作(background.cpp L181~185)(使用的地方有點太多 就不贅述了)

第四種operator是為了偵錯，因為在程式開發初期的時候，一次一次去用cout大法有點麻煩，所以直接寫了一個operator來cout所有user的數據，因為有時人物的動作會有點奇怪，在這時就可以使用此<<operator(userdown.cpp L422~437)(測試時才有使用最終版沒有在main中使用)
第五種operator是為了實行石頭掉落加速，寫了一個=operator(deathobstacle.cpp L49~54)(main.cpp L772)

### (D)
Const :
在user中為了判斷勝利需要讀取rival的位子，所以實作了一個getposition的const function(不需要改變參數)(userdown.cpp L396~399)(userdoen.cpp L355~358)，而在勝利畫面要判斷是誰贏也要讀取兩個user的死亡狀態，所以實作checkwin來讀取兩方的數值(userdown.cpp L380~382)。
Static:
本次有使用static的地方是在判斷滑鼠是否有在按鈕上的地方(main.cpp L401~405 468~469 521~522 586~588)，還有按鈕音效的地方(按鈕是否被按下)，如果在前者沒有使用static變數，則遊戲畫面的滑鼠按鈕回變成是滑鼠要一直在按鈕上移動卷軸才會打開，而後者沒有使用static變數的話，按一下按鈕可能會發出好幾次音效。
還有在一些固定的參數例如視窗的width height也是使用static來製做
