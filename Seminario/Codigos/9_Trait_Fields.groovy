trait Counter {
    private int count = 0                   
    int count() { count += 1; count }       
}
class Foo implements Counter {}             
def f = new Foo()
println(f.count())
println(f.count())

