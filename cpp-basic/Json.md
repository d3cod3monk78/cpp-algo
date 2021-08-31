<!-- Json tutorial -->
# JSON Crash Course

> By **d3cod3monk**

---

![JSON logo](https://www.json.org/img/json160.gif)

## Content

- [JSON Crash Course](#json-crash-course)
  - [Content](#content)
  - [What is JSON](#what-is-json)
  - [Data types in JSON](#data-types-in-json)
  - [How JSON works](#how-json-works)
  - [JSON Syntax rule](#json-syntax-rule)
  - [JSON Example](#json-example)
  - [Transform Javascript object into JSON object](#transform-javascript-object-into-json-object)
  - [Transform JSON object into Javascript object](#transform-json-object-into-javascript-object)
  - [Array of JSOn objects](#array-of-json-objects)

## What is JSON

- JavaScript Object Notation
- Lightweight data-interchange format
- Based on subset of JavaScript
- Easy to read and write
- Often use with **AJAX**

## Data types in JSON

- **Number:** No difference between integer and floats
![Number process](https://www.json.org/img/number.png)
- **String:** Strings of unicode characters. Use double quotes
![String process](https://www.json.org/img/string.png)
- **Boolean:** *True* or *False*
- **Array:** Ordered list of 0 or more values
![JSON array process](https://www.json.org/img/array.png)
- **Object:** Unordered collection of key/value pairs
![JSON Object process](https://www.json.org/img/object.png)
- **Null:** Empty value

---

## How JSON works

![How JSON works](https://www.json.org/img/value.png)

![How whitespace checking](https://www.json.org/img/whitespace.png)

---

## JSON Syntax rule

- Use key/value pairs

```JSON
    {
        "name" : "Dev"
    }
```

- Use double quotes around key and value
- Must use specified data types
- File type is *.json*
- *MIME* type is **Application/json**

---

## JSON Example

```JSON
    {
        "name": "Dev Marlon" ,
        "age": 26 ,
        "address": {
            "street": "Colombo rd" ,
            "City": "Colombo"
        } ,
        "Education": ["Bsc in Software engineering" , "Bsc(Hons) Computer Engineering"]
    }
```

---

## Transform Javascript object into JSON object

```Javascript
    const person = {
        name: "Dev" ,
        age: "age"
    };

    //By this we can transform person js object into JSON object
    person = JSON.stringify(person);

```

---

## Transform JSON object into Javascript object

```JSON
    //Json object
    {
        "name": "Dev" ,
        "age": 25
    }
```

```Javascript
    const person = JSON.parse(JSONObject);
```

---

## Array of JSOn objects

```JSON
    [
        {
            //object details
        } ,
        {
            //object details
        }
    ]
```

or we can use

```JSON
    {
        someName: [
            {
                //object details
            } ,
            {
                //object details
            }
        ]
    }
```
