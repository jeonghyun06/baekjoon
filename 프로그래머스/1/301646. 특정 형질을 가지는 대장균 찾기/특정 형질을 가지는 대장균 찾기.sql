-- 코드를 작성해주세요
select count(*) COUNT
from ecoli_data
where ((genotype & 4) or (genotype & 1)) and not (genotype & 2)