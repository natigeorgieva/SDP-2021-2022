#include <iostream>
#include <queue>
#include <string>


/**
	Функция, която проверява дали един символен низ се
	състои само от цифри

	@param[in] s Входния низ

	@returns   Връща true, ако е изпълнено условието, в
			   противен случай false
*/
bool isInteger(std::string s) {
	bool state = true;		///Флаг, с който означаваме дали текущия низ съдържа само цифри

	for (int i = 0; state && i < s.length(); i++) {
		if (!isdigit(s[i])) {		///Ако намерим символ различен от цифра сваляме флага
			state = false;
		}
	}

	return state;
}


/**
	Функция, която конвертира даден символен низ в целочислена стойност

	@param[in] s Входния низ

	@returns   Връща числото в символния низ като целочислена данна
*/
int toInteger(std::string s) {
	int num = 0; ///Текущото число

	for (int i = 0; i < s.length(); i++) {
		num = 10 * num + (s[i] - '0');	///Умножаваме текущото число с 10 и го събираме с текущата цифра
	}

	return num;

}


/**
	функция, която въвежда в реферирана опашка от цели числа,
	докато не се въведе нещо, което не е цяло число

	@param[in, out] q Подадена опашка, в която пълним цели числа

*/
void inputQueue(std::queue<int>& q) {
	std::string input;  ///Низ, в който пазим текущия вход от клавиатурата

	while(1) {
		std::cin >> input;		///Извличаме от потока низ

		if (isInteger(input)) {			///Ако извлечения низ е число
			q.push(toInteger(input));   ///Преобразуваме го в такова и го слагаме в опашката
		}
		else {							///В противен случай терминираме функцията
			return;
		}
	}
}


///Функция принтираща опашкана екрана. За по-подробно обяснение се консултирайте с
///решените примери от предишното упашнение
void outputQueue(std::queue<int> q) {

	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}

/**
    Фунцкия, която проверява дали елементите в опашка са подредени в
    растящ ред, т.е. елемента, който седи на чело на опашката е по-малък
    от всички останали
*/
bool isAscending(std::queue<int> q){

    ///Докато в опашката има поне два елемента
    while(q.size()>=2){
        int temp = q.front(); ///Запазваем стойността на предния елемент
        q.pop();              ///и го премахваме

        if(q.front() < temp){ ///Ако текущия преден елемент е по-малък от предишния преден, значи не е в нарастващ ред
            return false;     ///Следователно ввръщаме false - не е подредена
        }
    }

    return true; ///Ако за цялата опашка не сме намерили противоречие то тя е продредена в растящ ред и връщаме true

}

std::queue<std::queue<int>> task4(std::queue<std::queue<int>> stst, int a, int b){
    std::queue<std::queue<int>> res;

    ///Обхождаме поелементно опашката от опашки
    while(!stst.empty()){
        std::queue<int> temp = stst.front();  ///Запазваме си копие на предния елемент на опашката от опашки
        int sum = 0;        ///Текущата сума елементите

        while(!temp.empty()){ ///Сумираме елементите на опашката
            sum+= temp.front();
            temp.pop();
        }

		///Ако сумата удовлетворява условието пъхаме текущата опашка в резултатната опашката от опашки
        if(sum>=a && sum<= b){
            res.push(stst.front());
        }

        stst.pop(); ///Премахваме опашката, която сме обработвали до сега, за да обработим и другите
    }

    return res;
}

int main(){
    std::queue<std::queue<int>> stst;

    for(int i = 0; i< 5; i++){
        std::queue<int> inpt;
        inputQueue(inpt);
        stst.push(inpt);
    }

    std::queue<std::queue<int>> res = task4(stst, 10, 50);

    while(!res.empty()){
        outputQueue(res.front());
        res.pop();
    }
}
