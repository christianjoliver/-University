import java.util.HashMap;
import java.util.Map;

public class Tabelas {
	Map <String, Variaveis> Mapa = new HashMap <String, Variaveis>();


	public void insere(String chave, String valor, String tipo)
	{

		Variaveis Objeto = new Variaveis();
		Objeto.setNome(chave);
		Objeto.setTipo(tipo);
		Objeto.setValor(valor);

		Mapa.put(chave, Objeto);
	}

	public void imprime()
	{
		System.out.println("Chave	Valor	Tipo");
		for(String key: Mapa.keySet()){
			String v = Mapa.get(key).getValor();
			String t = Mapa.get(key).getTipo();
			System.out.println(key +"	" + v+"	" +t);
		}
	}

	public String buscaVar(String key)
	{
		String name = Mapa.get(key).getValor();
		return name;
	}
}