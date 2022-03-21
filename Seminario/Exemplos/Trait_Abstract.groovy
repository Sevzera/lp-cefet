trait Greetable {
    abstract String name()                              
    String greeting () { "Hello, ${name()}!" }           
}

class Person implements Greetable {                     
    String name () { 'Bob' }                             
}

def p = new Person()
println(p.greeting())


