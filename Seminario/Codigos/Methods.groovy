class Main {

    static def olaMetodos () {
        println ('Ola Metodos!\n')
    }
        
    static def int somaNumeros (int a, int b) {
        return a + b;
    }

    static def String concatenaString (String a, String b) {
        return a + b;
    }

    static def teste (a, b) {
        return a + b;
    }

    static void main (String[] args) {
        olaMetodos();
        
        println('somaNumeros = ' + somaNumeros(1,2));
        println('concatenaString = ' + concatenaString('Ola', ' Metodos'));
        
        println('\n');
        
        println('teste = ' + teste(1,2));
        println('teste = ' + teste('Ola', ' Metodos'));        
    }

}


