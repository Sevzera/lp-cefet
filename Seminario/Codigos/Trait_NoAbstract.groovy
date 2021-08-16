trait FlyingAbility {                           
        String fly() { "I'm flying!" }          
}

class Bird implements FlyingAbility {}          
def b = new Bird()                              
println(b.fly())

