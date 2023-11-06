# C++ Factory Pattern Example

This repository contains a simple implementation of the Factory Pattern in C++. The Factory Pattern is a creational design pattern that provides an interface for creating objects but allows subclasses to alter the type of objects that will be created.

## How It Works

In this example, we have defined an abstract `Product` class and two concrete classes, `ConcreteProduct1` and `ConcreteProduct2`, which inherit from the abstract class. A `Factory` class is responsible for creating instances of these concrete products based on a product type.

You can use the Factory Pattern to create objects without specifying the exact class of object to be created. It offers flexibility and extensibility when working with object creation.
