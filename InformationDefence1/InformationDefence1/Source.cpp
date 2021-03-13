#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <bitset>

std::string readFromFile(const std::string& wayToFile);
std::string encryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys);
void writeToFile(const std::string& wayToFile, const std::string& data);
std::string reEncryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys);

int main() {
	std::string wayToFile {"C:/Users/Kalina/Desktop/InformationDefence/some.docx"};
	std::string line;
	std::string informationFromFile;
	std::ifstream in(wayToFile, std::ios::binary);
	
	if (!in.is_open()) {
		std::cout << "Error file openning!" << std::endl;
		exit(1);
	}
	// Создать файл программой Microsoft Word с расширением * .doc,
	//содержащий текст “Veni, vidi, vici”.Создать программу на языке
	//С++, определяющую его длину в байтах.Создать файл программой Microsoft Word с расширением* .doc

	in.seekg(0, std::ios::end);
	std::cout << "Bytes read: " << static_cast<int>(in.tellg()) << std::endl;

	//Создать программу на языке С++, подсчитывающую частоту
	//	появления каждого байта в произвольном файле.

	in.seekg(0, std::ios::beg);
	char byte;
	size_t count{ 0 };
	std::map<char, size_t> countBytes;

	while (in.get(byte)) {
		if (countBytes.find(byte) == countBytes.end()) {
			countBytes[byte] = 0;
		}
		++countBytes[byte];
		++count;
	}

	std::cout << "Bytes read from file: " << count << std::endl;
	for (auto it = countBytes.begin(); it != countBytes.end(); ++it) {
		std::cout << "Byte: " << it->first << "\tValue: " << it->second << "\tFrequency: "
			<< static_cast<double>(countBytes[it->second]) / count << std::endl;
	}

	in.close();

	//	Создать программу на языке С++, реализующую шифр вертикальной
	//	перестановки для произвольного дискового файла(число столбцов
	//	для шифра вертикальной перестановки – 5).В случае, если длина
	//	файла не кратна 5, дописывать его символами z.Ключ – подстановку
	//	порядка 5, вводить из отдельного файла с именем «key.txt».
	//	Программа должна иметь расшифрование.

	const size_t columns = 5;
	size_t index = 0;
	wayToFile = "C:/Users/Kalina/Desktop/InformationDefence/data.txt";
	//wayToFile = "C:/Users/Kalina/Desktop/InformationDefence/some.docx";
	std::string encriptionData{ "" };
	std::string dataFromFile{ "" };
	std::string dataFromKeyFile{ "" };
	std::string wayToEncriptionFile{ "C:/Users/Kalina/Desktop/InformationDefence/encriptionData.txt" };
	//std::string wayToEncriptionFile{ "C:/Users/Kalina/Desktop/InformationDefence/some1.docx" };
	std::string wayToKeyFile{ "C:/Users/Kalina/Desktop/InformationDefence/key.txt" };
	std::vector<size_t> keys(columns);
	std::string reEncriptionData{ "" };

	dataFromFile = readFromFile(wayToFile);
	dataFromKeyFile = readFromFile(wayToKeyFile);
	std::cout << "DATA FROM KEY FILE: " << dataFromKeyFile << std::endl;
	for (size_t i = 0; i < dataFromKeyFile.size(); ++i) {
		if (isdigit(dataFromKeyFile[i])) {
			keys[index++] = static_cast<size_t>(dataFromKeyFile[i]) - '0';
			//std::cout << static_cast<size_t>(dataFromKeyFile[i]) - '0' << " ";
		}
	}

	encriptionData = encryptionDataFunction(dataFromFile, columns, keys);

	/*std::cout << "EncryptionDataFunction: " 
		<< encriptionData << std::endl;*/
	writeToFile(wayToEncriptionFile, encriptionData);
	reEncriptionData = reEncryptionDataFunction(encriptionData, columns, keys);

	writeToFile("C:/Users/Kalina/Desktop/InformationDefence/reEncriptionData.txt", reEncriptionData);
	//writeToFile("C:/Users/Kalina/Desktop/InformationDefence/some3.docx", reEncriptionData);

	//std::cout << std::endl << /*"reEncriptionDataFunction: " <<*/ reEncriptionData << std::endl;

	//std::string readSome = readFromFile("C:/Users/Kalina/Desktop/InformationDefence/some.docx");
	//writeToFile("C:/Users/Kalina/Desktop/InformationDefence/some5.docx", readSome);
	//std::ifstream in2("C:/Users/Kalina/Desktop/InformationDefence/some5.docx", std::ios::binary);
	//std::cout << "Read from some5: " << std::endl << std::endl;
	//if (!in2.is_open()) {
	//	std::cout << "Error file openning!" << std::endl;
	//	exit(1);
	//}
	// Создать файл программой Microsoft Word с расширением * .doc,
	//содержащий текст “Veni, vidi, vici”.Создать программу на языке
	//С++, определяющую его длину в байтах.Создать файл программой Microsoft Word с расширением* .doc

	//in2.seekg(0, std::ios::end);
	//std::cout << "Bytes read: " << static_cast<int>(in2.tellg()) << std::endl;

	//Создать программу на языке С++, подсчитывающую частоту
	//	появления каждого байта в произвольном файле.

	//in2.seekg(0, std::ios::beg);
	///*char*/ byte;
	///*size_t*/ count = 0 ;
	//std::map<char, size_t> countBytes2;

	//while (in2.get(byte)) {
	//	if (countBytes2.find(byte) == countBytes2.end()) {
	//		countBytes2[byte] = 0;
	//	}
	//	++countBytes2[byte];
	//	++count;
	//}

	/*std::cout << "Bytes read from file: " << count << std::endl;
	for (auto it = countBytes2.begin(); it != countBytes2.end(); ++it) {
		std::cout << "Byte: " << it->first << "\tValue: " << it->second << "\tFrequency: "
			<< static_cast<double>(countBytes2[it->second]) / count << std::endl;
	}

	in2.close();
	std::cout << "End Read from some5: " << std::endl << std::endl;
	auto item = countBytes.begin();
	auto item2 = countBytes2.begin();
	for (; item != countBytes.end() && item2 != countBytes2.end(); ++item, ++item2)
	{
		if ((item->first != item2->first) || (item->second != item2->second)) {
			std::cout << item->first << " " << item->second << " " << item2->first << item2->second << std::endl;
			std::bitset<8> bit(item->first);
			std::cout << bit;
			break;
		}
	}*/
	/*readSome = readFromFile("C:/Users/Kalina/Desktop/InformationDefence/some5.docx");
	writeToFile("C:/Users/Kalina/Desktop/InformationDefence/some6.docx", readSome);*/
	return 0;
}

std::string readFromFile(const std::string& wayToFile)
{
	std::ifstream in(wayToFile, std::ios::binary);
	std::string informationFromFile{""};
	std::string buffer{""};

	if (!in.is_open()) {
		std::cout << "Error file openning!" << std::endl;
		exit(1);
	}

	while (getline(in, buffer)) { 
		informationFromFile += buffer; 
		informationFromFile += "\n";
	}
	informationFromFile = informationFromFile.erase(informationFromFile.size() - 1);
	in.close();
	return informationFromFile;
}

std::string reEncryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys) {
	size_t rows = data.size() / columns;
	size_t indexVector{ 0 };
	std::string reEncryptionData{ "" };

	for (size_t i = 0; i < rows; ++i) {

		for (size_t j = 0; j < columns; ++j) {
			indexVector = std::find(keys.begin(), keys.end(), j + 1) - keys.begin();
			//std::cout << std::endl << "Coordinates: " << indexVector << " " << i + (indexVector/* - 1*/) * rows << std::endl;
			reEncryptionData += data[i + (indexVector /*- 1*/) * rows];
		}
	}
	return reEncryptionData;
}

std::string encryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys) {
	std::string resultData{ "" };
	std::string resultDataString{ "" };
	size_t zCount = columns - data.size() % columns;
	size_t index{ 0 };

	for (size_t i = 0; i < data.size(); ++i) {
		resultData += data[i];
	}

	for (size_t i = 0; i < zCount; ++i) {
		resultData.append("z");
	}

	//std::cout << resultData << std::endl;

	for (auto i : keys) {
		index = 0;
		while (i + index * columns - 1 < resultData.size()) {
			resultDataString += resultData[i - 1 + index++ * columns];
		}
	}

	return resultDataString;
}

void writeToFile(const std::string& wayToFile, const std::string& data)
{
	std::ofstream out(wayToFile, std::ios::binary);
	
	if (!out.is_open()) {
		std::cout << "Error file openning!" << std::endl;
		exit(1);
	}

	out << data;

	out.close();
}