class Outer {
    private String privateStr

    def callInnerMethod() {
        new Inner().methodA()       
    }

    class Inner {                   
        def methodA() {
            println "${privateStr}." 
        }
    }
}


