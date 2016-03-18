# Building the project

1. Run `vagrant up`. Vagrant will set up the development
   environment. This may take a long time, especially the first time.
1. Run `vagrant exec run`. Now, the project will be built and ran.

Now, visit
[http://localhost:8080/hello/english](http://localhost:8080/hello/english),
you should see a page saying "Hello!".

To exit, hit Ctrl+C to stop the server. If you want to exit vagrant as
well, run `vagrant halt`.

# Libraries used

* [CppCMS](http://cppcms.com/wikipp/en/page/cppcms_1x): C++ Web
  Development Framework
* [sqlite\_modern\_cpp](https://github.com/aminroosta/sqlite_modern_cpp)
  A lightweight modern wrapper around sqlite C api.
