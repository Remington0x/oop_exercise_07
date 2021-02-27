#include "document.hpp"

int main() {
	TDocument<int> doc;
	std::string s;
	while (std::cin >> s) {
		if (s == "n") {
			doc.CreateNew();
			std::cout << "Created new document" << std::endl;
		} else if (s == "o") {
			std::cin >> s;
			FILE* in = fopen(s.c_str(), "rb");
			if (in == NULL) {
				std::cout << "No such file on directory" << std::endl;
			} else {
				doc.LoadFromFile(in);
				std::cout << "Loaded document from " << s << std::endl;
				fclose(in);
			}
		} else if (s == "s") {
			std::cin >> s;
			FILE* out = fopen(s.c_str(), "wb");
			if (out == NULL) {
				std::cout << "No such file on directory" << std::endl;
			} else {
				doc.SaveToFile(out);
				std::cout << "Saved document to " << s << std::endl;
				fclose(out);
			}
		} else if (s == "+") {
			size_t pos;
			unsigned short type;
			std::cin >> pos >> type;
			doc.Add(pos, type);
		} else if (s == "-") {
			size_t pos;
			std::cin >> pos;
			doc.Delete(pos);
		} else if (s == "p") {
			std::cout << "Printing document:" << std::endl;
			std::cout << doc;
		} else if (s == "u") {
			doc.Undo();
		} else if (s == "h") {
			std::cout << "\'n\' - create new document" << std::endl;
			std::cout << "\'o\' - open document" << std::endl;
			std::cout << "\'s\' - save document" << std::endl;
			std::cout << "\'+\' - add a figure" << std::endl;
			std::cout << "\'-\' - remove a figure" << std::endl;
			std::cout << "\'p\' - print document" << std::endl;
			std::cout << "\'u\' - undo changes" << std::endl;
			std::cout << "\'h\' - show this message" << std::endl;
		} else {
			std::cout << "Unknown command. Type \'h\' to show help" << std::endl;
		}
	}
	return 0;
}
