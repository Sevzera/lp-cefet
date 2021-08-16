interface Greeter {                                         
    void greet(String name)                                 
}

class SystemGreeter implements Greeter {                    
    void greet(String name) {                               
        println "Hello $name"
    }
}

