trait Named {
    String name                             
}

class Person implements Named {}            
def p = new Person(name: 'Bob')
println(p.name);

