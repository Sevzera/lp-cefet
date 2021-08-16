class Main {

    static void main (String[] args) {

        def a = 2;
        println('a = ' + a)
        a = 'Oi';
        println('a = ' + a);

        int b = 3;
        println('b = ' + b);

        String c = "Ola";
        println('c = ' + c);

        def x = 0..5;
        println('x = ' + x);
        println('x[2] = ' + x.get(2));

        def heterogeneous = [1, "a", true];
        println('heterogeneous = ' + heterogeneous);

    }


}

