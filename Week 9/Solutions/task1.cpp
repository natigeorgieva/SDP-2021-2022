#include <iostream>
#include <queue>
#include <string>
#include <stack>

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
    Функция, която проверява дали елементите на
    подадената опашка образуват палиндром. Алгоритъма е реализиран
    с помощен стек и опашка. Докато в подадената опашка има елементи
    пъхаме първия елемент в стека (така обръщаме подредбата на елементите в опашката)
    и в опашката (така запазваме оригиналната подредба). Сега ако опашката е образувала
    палиндом то всеки два поредни елемента в двете помощни структури трябва да си съпадат.

    @param[in] q Опашката, чиито елементи ще проверяваме

    @returns true - ако обрзуват  палиндром
             false - в противен случай

*/
bool isPalindrome(std::queue<int> q){
    std::stack<int> tempSt; ///Помощен стек, в който ще обърнем елементите от опашката
    std::queue<int> tempQ;  ///Нова опашка, където ще пазим елементите на подадената

    ///Докато има елементи в опашката
    while(!q.empty()){
        ///Пъхаме предния елемент на опашакта в помощните стек и опашка
        tempSt.push(q.front());
        tempQ.push(q.front());

        q.pop(); ///премашхваме предния елемент
    }

    ///Докато има елементи в помощния стек
    while(!tempSt.empty()){
        ///Ако два текущи елементи в помощните структури се разминават то опашката не е образувала палиндром
        if(tempSt.top() != tempQ.front()){
            return false;
        }

        ///Премахваме си първите два елемента за помощните структури, за да достъпим следващите елементи
        tempSt.pop();
        tempQ.pop();
    }

    return true;
}

int main(){
    std::queue<int> inpt;

    inputQueue(inpt);
    std::cout<<"Is the queue palindrome : "<<(isPalindrome(inpt) ? "Yes" : "No");
}
