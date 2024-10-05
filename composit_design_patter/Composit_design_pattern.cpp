#include<bits/stdc++.h>
using namespace std;

class fileInterface {
public:
    virtual void compress() = 0;
    virtual void extract() = 0;  
    virtual ~fileInterface() {}
};

class TextFile : public fileInterface {
private:
    string filename;
public:
    TextFile(string name) : filename(name) {}  
    
    void compress() override {
        cout << filename << ".txt file is being compressed" << endl;
    }

    // empty because no use
    void extract() override { 
    }
};

class ImageFile : public fileInterface {
private:
    string filename;
public:
    ImageFile(string name) : filename(name) {}

    void compress() override {
        cout << filename << ".jpg file is being compressed" << endl;
    }

    void extract() override {
    }
};

class ZipFile : public fileInterface {
private:
    string filename;
public:
    ZipFile(string name) : filename(name) {}

    void compress() override {
        cout << filename << ".zip file is being compressed" << endl;
    }

    void extract() override {
        cout << filename << ".zip file is being extracted" << endl;
    }
};

class Folder : public fileInterface { 
private:
    string name;
    vector<fileInterface*> contents;
public:
    Folder(string foldername) : name(foldername) {}

    void add(fileInterface* entity) {
        contents.push_back(entity);
    }

    void compress() override {
        cout << "Compressing folder: " << name << endl;
        for (fileInterface* entity : contents) {
            entity->compress(); 
        }
    }

    void extract() override {
        cout << "Extracting folder: " << name << endl;
        for (fileInterface* entity : contents) {
            entity->extract(); 
        }
    }

    ~Folder() {
        for (fileInterface* entity : contents) {
            delete entity;
        }
    }
};

int main() {
    fileInterface* file1 = new TextFile("Document1");
    fileInterface* file2 = new ImageFile("Image1");
    fileInterface* file3 = new ZipFile("Archive1");

    Folder* folder = new Folder("MyFolder");

    folder->add(file1);
    folder->add(file2);
    folder->add(file3);

    Folder* subFolder = new Folder("SubFolder");
    subFolder->add(new TextFile("Document2"));
    folder->add(subFolder);

    folder->compress();

    delete folder;  

    return 0;
}
