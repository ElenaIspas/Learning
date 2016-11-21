//
//  TestClass.h
//  testeOctombrie
//
//  Created by Elena Ispas on 17/10/16.
//  Copyright © 2016 Elena Ispas. All rights reserved.
//

#ifndef TestClass_cpp
#define TestClass_cpp

#include <set>
#include <cassert>
#include <iostream>

static  int THROW_EXECPTION = 0;

struct alignas(16) A
{
	static std::set<const A*> sObjects;
 
	A()
	{
		assert(reinterpret_cast<uintptr_t>(this) % alignof(A) == 0 && "this is constructed at an unsupported address");
 
		sObjects.insert(this);
		std::cout<<"Constructor"<<std::endl;
	}
 
	A(const A& other)
	{
		assert(reinterpret_cast<uintptr_t>(this) % alignof(A) == 0 && "this is constructed at an unsupported address");
		assert(sObjects.find(&other) != sObjects.end() && "other was not correctly created!");
    
        if(THROW_EXECPTION != 0)
            throw "error in copy constructor";
            
		sObjects.insert(this);
		std::cout<<"Copy constructor"<<std::endl;
	}
 
	A(A&& other)
	{
		assert(sObjects.find(&other) != sObjects.end() && "other was not correctly created!");
 
		sObjects.insert(this);
		std::cout<<"Move constructor"<<std::endl;
	}
 
	~A()
	{
		assert(sObjects.find(this) != sObjects.end() && "this was not correctly created!");
 
		sObjects.erase(this);
		std::cout<<"Destructor"<<std::endl;
	}
 
	A& operator=(const A& other)
	{
		assert(sObjects.find(this) != sObjects.end() && "this was not correctly created!");
		assert(sObjects.find(&other) != sObjects.end() && "other was not correctly created!");
 
		std::cout<<"lvalue copy operator"<<std::endl;
 
		return *this;
	}
 
	A& operator=(A&& other)
	{
		assert(sObjects.find(this) != sObjects.end() && "this was not correctly created!");
		assert(sObjects.find(&other) != sObjects.end() && "other was not correctly created!");
 
		std::cout<<"rvalue copy operator"<<std::endl;
 
		return *this;
	}
 
	void Use()
	{
		assert(sObjects.find(this) != sObjects.end() && "this is used before is created!");
 
		std::cout<<"Use"<<std::endl;
	}
};

#endif /* TestClass_cpp */
