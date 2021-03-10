---
id: getting-started.first
title: A first project
prev: getting-started.tools
next: getting-started.objectwrap
---

Before you start, make sure you've got all the necessary [prerequisites](prerequisites) and [tools](tools) installed.

As you select where to begin, you should be aware that N-API operates at two levels which we can think of as the "C level" and the "C++ level". 

The "C level" code is built entirely into Node itself and is very well documented on the [Node documentation pages](https://nodejs.org/api/n-api.html). If you need low-level access to the intricacies of Node, this is the tool for you. 

Alternatively, there is the [node-addon-api ](https://github.com/nodejs/node-addon-api) package which adds a C++ wrapper to the N-API code built into Node. This package makes working with N-API much easier as it implements a very nice object model and abstracts away much of the detailed coding that would otherwise be required, while retaining the N-API promise of ABI stability and forward compatibility.

This tutorial uses `node-addon-api`.

> N-API has been in public release and active development starting with Node 8.0.0. Since then, it's undergone a number of refinements. This tutorial has been tested with Node 10.10.0 and is known to fail with older versions of Node. You will need a copy of Node that supports N-API in order to develop and run N-API code. To see which versions of Node support N-API, refer to the [N-API Version Matrix](https://nodejs.org/api/n-api.html#n_api_n_api_version_matrix). You can determine the version of Node you're running with the command `node -v`.

## Creating a project

The easiest way to create a new N-API project is to use the [`generator-napi-module`](https://www.npmjs.com/package/generator-napi-module) package. As the package documentation describes, `generator-napi-module` relies on [Yeoman](http://yeoman.io) which must also be installed:

```bash
npm install -g yo
npm install -g generator-napi-module
```

On some systems, you may receive the error `Error: EACCES: permission denied, access`. In that case, on Mac and Linux systems you need to run the commands with elevated privileges:

```bash
sudo npm install -g yo
sudo npm install -g generator-napi-module
```

> Using [`nvm`](https://github.com/creationix/nvm) is an _excellent_ way to banish permission issues. 

Then enter these commands to generate a new project:

```bash
mkdir hello-world
cd hello-world
yo napi-module
```

Here are the prompts you'll see and some suggested responses:

```
package name: (hello-world) 
version: (1.0.0) 
description: A first project.
git repository: 
keywords: 
author: Your name goes here
license: (ISC) 
```

Yeoman will display the generated `package.json` file here.

```
Is this OK? (yes) yes
? Choose a template Hello World
? Would you like to generate TypeScript wrappers for your module? No
```

Yeoman will now build your "Hello World" add-on module. 

At this point, you might try running `npm test` to make sure everything is correctly installed:

```bash
npm test
```

## Project structure

At this point you have a completely functional N-API module project. The project files are structured according to N-API best practices. It should look like this:

```
.
├── binding.gyp                         Used by gyp to compile the C code
├── build                               The intermediary and final build products
│   └── < contents not shown here >
├── lib                                 The N-API code that accesses the C/C++ binary
│   └── binding.js
├── node_modules                        Node modules required by your project
│   └── < contents not shown here >
├── package.json                        npm description of your module
├── package-lock.json                   Used by npm to insure deployment consistency
├── src                                 The C/C++ code
│   └── hello_world.cc
└── test                                Test code
    └── test_binding.js
```

Let's take a look at the essential files.

## package.json

[**package.json**](https://github.com/nodejs/node-addon-examples/blob/master/a-first-project/node-addon-api/package.json)

`embed:a-first-project/node-addon-api/package.json`

This is a typical `package.json` file as generated by [Yeoman](http://yeoman.io) from the responses we entered earlier to the `yo napi-module` command. There are a couple of entries of interest here. 

Notice the [`node-addon-api`](https://github.com/nodejs/node-addon-api) dependency. This package, which is not strictly a part of Node, adds a C++ wrapper to the C API implemented in Node. The package makes it very straightforward to create and manipulate JavaScript objects inside C++. The package is useful even if the underlying library you're accessing is in C. 

There is also a `"gypfile": true` entry which informs npm that your package requires a build using the capabilities of the `node-gyp` package which is covered next. 

## binding.gyp

[**binding.gyp**](https://github.com/nodejs/node-addon-examples/blob/master/a-first-project/node-addon-api/binding.gyp)

`embed:a-first-project/node-addon-api/binding.gyp`

One of the challenges of making C/C++ code available to Node is getting the code compiled, linked, and packaged for a variety of operating systems and architectures. Historically, this would require learning the intricacies of a variety of build tools across a number of operating systems. This is the specific issue GYP seeks to address.  

Using [GYP](https://gyp.gsrc.io/index.md) permits having a single configuration file that works across all platforms and architectures GYP supports. (It's GYP, by the way, that requires Python).

[node-gyp](https://github.com/nodejs/node-gyp) is a command line tool built in Node that orchestrates GYP to compile your C/C++ files to the correct destination. When npm sees the `"gypfile": true` entry in your `package.json` file, it automatically invokes its own internal copy of `node-gyp` which looks for this `binding.gyp` file which must be called `binding.gyp` in order for node-gyp to locate it.

The `binding.gyp` file is a GYP file which is thoroughly documented [here](https://gyp.gsrc.io/docs/UserDocumentation.md). There is also specific information about building libraries [here](https://gyp.gsrc.io/docs/UserDocumentation.md#skeleton-of-a-typical-library-target-in-a-gyp-file).

## src/hello_world.cc

[**hello_world.cc**](https://github.com/nodejs/node-addon-examples/blob/master/a-first-project/node-addon-api/src/hello_world.cc)

`embed:a-first-project/node-addon-api/src/hello_world.cc`

This is perhaps the simplest useful(?) N-API file you can have.

The file defines a C++ `Method` function that takes a single `Napi::CallbackInfo&` argument. This `info` argument is used to access the JavaScript environment, including any JavaScript arguments that might be passed in. 

> `info` is an array of JavaScript arguments.

In this case, the C++ `Method` function uses the `info` argument to create a `Napi::Env` local that is then used to create a `Napi::String` object which is returned with the value "world".

The C++ `Init` function shows how to set a single export value for the native add-on module. In this case the name of the export is "HelloWorld" and the value is the `Method` function. 

The `NODE_API_MODULE` macro at the bottom of the C++ file insures that the `Init` function is called when the module is loaded.  

## lib/binding.js

[**binding.js**](https://github.com/nodejs/node-addon-examples/blob/master/a-first-project/node-addon-api/lib/binding.js)

`embed:a-first-project/node-addon-api/lib/binding.js`

This JavaScript file defines a JavaScript class that acts as an intermediary to the C++ binary. 

In this case, the sole export of the binding is the `HelloWorld` function. 

## test/test_binding.js

[**test_binding.js**](https://github.com/nodejs/node-addon-examples/blob/master/a-first-project/node-addon-api/test/test_binding.js)

`embed:a-first-project/node-addon-api/test/test_binding.js`

This code demonstrates how to load and call the `HelloWorld` function using JavaScript. Recall that the sole export from the binding is the `HelloWorld` function. The function is loaded into the `HelloWorld` variable using the `require` command. 

The `testBasic` function then calls the `HelloWorld` function and verifies the result. 

## Conclusion

This project demonstrates a very simple N-API module that exports a single function. In addition, here are some things you might want to try:

- Run `test_binding.js` in your debugger. See if you can step through the code to get a better understanding of how it works. What sort of visibility are you getting into the JavaScript object created by the C++ code?

- Modify `test_binding.js` to use the C++ binary module directly instead of through `binding.js`. Step through the code in your debugger to see how things are different.

- Modify `hello_world.cc` to access arguments passed from the JavaScript. Hint: The `node-addon-api` module comes with [examples](https://github.com/nodejs/node-addon-api#examples).  

## Resources

- [node-addon-api](https://github.com/nodejs/node-addon-api) Documentation

- The [generator-napi-module](https://www.npmjs.com/package/generator-napi-module) Package

- The [node-gyp](https://www.npmjs.com/package/node-gyp) Package

- [GYP](https://gyp.gsrc.io) and [.gyp file](https://gyp.gsrc.io/docs/UserDocumentation.md) Documentation.

- [Yeoman](http://yeoman.io)