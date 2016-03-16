# Building the project

1. Run `vagrant up`. Vagrant will set up the development
   environment. This can take a long time.
1. Run `vagrant ssh` to connect to the development.

Run the following commands on the developmont box:

    cd /vagrant
    mkdir build
    cd build
    cmake ..
    make

To run the project, now write the following commands while in the
development box:

    cd /vagrant/build
    ./Recipe-Manager -c ../config.json

Now, visit
[http://localhost:8080/hello/english](http://localhost:8080/hello/english),
you should see a page saying "Hello!".


# Libraries used

* [CppCMS](http://cppcms.com/wikipp/en/page/cppcms_1x): C++ Web
  Development Framework
* [sqlite\_modern\_cpp](https://github.com/aminroosta/sqlite_modern_cpp)
  A lightweight modern wrapper around sqlite C api.
