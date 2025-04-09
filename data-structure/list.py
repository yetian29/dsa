

def main():
    fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
    fruits.append('mango')
    fruits.extend(i for i in ['grape', 'tangerine'])
    fruits.insert(2, 'strawberry')
    fruits.remove('apple')
    fruits.pop()
    # fruits.clear()
    print(fruits.index('banana'))
    print(fruits.count('apple'))
    fruits.sort()
    fruits.reverse()
    print(fruits.copy())
    print(fruits)
    ...

if __name__ == "__main__":
    main()
