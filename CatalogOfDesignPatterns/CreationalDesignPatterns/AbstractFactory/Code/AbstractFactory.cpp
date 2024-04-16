#include <string>
#include <iostream>

// Abstract Products are : Document and Image
// Concrate Products are : xDocument's and xImage's

class Document{
public:
	virtual void printDoc()=0;
	std::string Context;
};

class WinDocument: public Document{
public:
	WinDocument() {
		this->Context = "This document is WinDocument";
	};
	void printDoc() override{
		std::cout << "Documents output : " << this->Context << std::endl;
	};
};

class UnixDocument: public Document{
public:
	UnixDocument() {
		this->Context = "This document is UnixDocument";
	};
	void printDoc() override{
		std::cout << "Documents output : " << this->Context << std::endl;
	};
};

class Image{
public:
	virtual void printImg() =0;
	std::string Context;
};

class WinImage: public Image{
public:
	WinImage(){
		this->Context = "Win Image";
	};
	void printImg() override{
		std::cout << "Image looks like : " << this->Context << std::endl;
	};
};

class UnixImage: public Image{
public:
	UnixImage(){
		this->Context = "Unix Image";
	};
	void printImg() override{
		std::cout << "Image looks like : " << this->Context << std::endl;
	};
};

// Abstract Factory
class DocumentFactory{
public:
	virtual Document* createDocument() = 0;
	virtual Image* createImage() = 0;
};

// Concrete Factories
class WinFactory: public  DocumentFactory{
public:
	Document* createDocument() override {
		return new WinDocument();
	};
	Image* createImage() override {
		return new WinImage();
	};
};

class UnixFactory: public DocumentFactory{
	Document* createDocument() override {
		return new UnixDocument();
	};
	Image* createImage() override {
		return new UnixImage();
	};
};

// Application

class FileFactory{
public:
	DocumentFactory *factory;
	FileFactory(DocumentFactory *f) {
		factory = f;
	}
};

int main() {
	FileFactory *myFac;
	std::string osType = "Unix";
	if (osType == "Unix")
		myFac = new FileFactory(new UnixFactory());
	else if (osType == "Win")
		myFac = new FileFactory(new WinFactory());
	Image *img = myFac->factory->createImage();
	img->printImg();
	Document *doc = myFac->factory->createDocument();
	doc->printDoc();
}