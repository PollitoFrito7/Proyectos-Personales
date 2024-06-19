//#include "stringPool.h"
//
//#include <fstream>
//using namespace std;
//
//void load(ifstream& file, tStringPool& stringPool) {
//	string aux;
//
//	file >> aux;
//
//	while (aux != "XXX") {
//
//	}
//}
//
//void increaseCapacity(tStringPool& stringPool) {
//	tStringPool aux = stringPool;
//
//	stringPool.capacity += Increment;
//
//	for (int i = 0; i < stringPool.counter; i++) {
//		stringPool.pool[i] = new string(aux.pool[i]);
//	}
//
//	for (int i = 0; i < stringPool.counter; i++) {
//			stringPool.pool[i] = aux.pool[i];
//	}
//
//	destroy(aux);
//}
//
//void destroy(tStringPool& stringPool) {
//	for (int i = 0; i < stringPool.counter; i++)
//		delete stringPool.pool[i];
//	
//	stringPool.counter = 0;
//	stringPool.capacity = Increment;
//}
//
//int main() {
//	tStringArray stringPool;
//	stringPool.pool[0] = new string("pitoybolas");
//}