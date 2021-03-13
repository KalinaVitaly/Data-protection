#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>

std::string readFromFile(const std::string& wayToFile);
std::string encryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys);
void writeToFile(const std::string& wayToFile, const std::string& data);
std::string reEncryptionDataFunction(const std::string& data, size_t columns, const std::vector<size_t>& keys);

int main() {
	std::string wayToFile {"C:/Users/Kalina/Desktop/������ ����������/some.docx"};
	std::string line;
	std::string informationFromFile;
	std::ifstream in(wayToFile, std::ios::binary);
	
	if (!in.is_open()) {
		std::cout << "Error file openning!" << std::endl;
		exit(1);
	}
	// ������� ���� ���������� Microsoft Word � ����������� * .doc,
	//���������� ����� �Veni, vidi, vici�.������� ��������� �� �����
	//�++, ������������ ��� ����� � ������.������� ���� ���������� Microsoft Word � �����������* .doc

	in.seekg(0, std::ios::end);
	std::cout << "Bytes read: " << static_cast<int>(in.tellg()) << std::endl;

	//������� ��������� �� ����� �++, �������������� �������
	//	��������� ������� ����� � ������������ �����.

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

	//	������� ��������� �� ����� �++, ����������� ���� ������������
	//	������������ ��� ������������� ��������� �����(����� ��������
	//	��� ����� ������������ ������������ � 5).� ������, ���� �����
	//	����� �� ������ 5, ���������� ��� ��������� z.���� � �����������
	//	������� 5, ������� �� ���������� ����� � ������ �key.txt�.
	//	��������� ������ ����� �������������.

	const size_t columns = 5;
	size_t index = 0;
	wayToFile = "C:/Users/Kalina/Desktop/������ ����������/data.txt";
	std::string encriptionData{ "" };
	std::string dataFromFile{ "" };
	std::string dataFromKeyFile{ "" };
	std::string wayToEncriptionFile{ "C:/Users/Kalina/Desktop/������ ����������/encriptionData.txt" };
	std::string wayToKeyFile{ "C:/Users/Kalina/Desktop/������ ����������/key.txt" };
	std::vector<size_t> keys(columns);

	dataFromFile = readFromFile(wayToFile);
	dataFromKeyFile = readFromFile(wayToKeyFile);
	std::cout << dataFromKeyFile << std::endl;
	for (size_t i = 0; i < dataFromKeyFile.size(); ++i) {
		if (isdigit(dataFromKeyFile[i])) {
			keys[index++] = static_cast<size_t>(dataFromKeyFile[i]) - '0';
			//std::cout << static_cast<size_t>(dataFromKeyFile[i]) - '0' << " ";
		}
	}
	std::cout << "encryptionDataFunction: " 
		<< (encriptionData = encryptionDataFunction(dataFromFile, columns, keys))
		<< std::endl;
	writeToFile(wayToEncriptionFile, encriptionData);

	std::cout << "reEncryptionDataFunction: " << reEncryptionDataFunction(encriptionData, columns, keys) << std::endl;

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

	while (getline(in, buffer)) { informationFromFile += buffer; }

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