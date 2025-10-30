select a.id, a.genotype, b.genotype parent_genotype
from ecoli_data a
left join ecoli_data b on a.parent_id = b.id
where (a.genotype | b.genotype) = a.genotype
order by id